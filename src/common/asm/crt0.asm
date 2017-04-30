%include '../mikeos/mikedev.inc'
bits 16

%define MAX_PARAMS	16
%define STACK_SIZE	512

GLOBAL __start
GLOBAL __Exit
EXTERN _main

EXTERN memory_initialise
EXTERN __stop_alldata__


section .text

; The memory layout should look like this:
; 0x0000			OS Kernel
; 0x8000			Binary Load Point
; 0x8000 + Binary Size		Heap Space
; 0x10000 - Stack Size		Stack Space

; Programs should use the heap to store any data

__start:
	; Program start routine --- called directly by the OS

	; The operating system should have passed SI as the parameters.
	; The string is converted into an array of parameters.

	; A zero value indicates no parameters
	cmp si, 0
	je .no_parameters

	; It may also be indicated by a blank string
	cmp byte [si], 0
	je .no_parameters
	
	mov bx, param_array
	mov cx, MAX_PARAMS
	mov dx, 1

.get_parameter:
	mov [bx], si
	add bx, 2

	mov al, ' '
	call os_string_tokenize

	cmp di, 0
	je .args_done

	inc dx
	mov si, di
	loop .get_parameter

.args_done:
	mov word [bx], 0
	mov [argc], dx


.init_heap:
	; Setup the heap after the end of the program data
	mov si, __stop_alldata__
	mov ax, si
	neg ax
	sub ax, STACK_SIZE	; Do not include stack space in the heap

	call memory_initialise
	jc .heap_error
	
	; Setup a new stack inside the program
	; The MikeOS should already have a stack
	; However the tiny memory model needs DS = SS 
	cli
	mov ax, ss
	mov [os_ss], ax
	mov [os_sp], sp
	mov ax, ds
	mov ss, ax
	mov sp, 0		; The stack starts at the end of memory space
	sti


.prepare_args:
	; Prepare to call the main function
	; It should look like this:
	; int main(int argc, char **argv);

	mov bx, argv0
	push bx

	mov dx, [argc]
	inc dx
	push dx


.enter_unreal_mode:
	mov dx, ss

	mov ax, cs
	mov si, gdt_table.code
	call modify_selector

	mov ax, ds
	mov si, gdt_table.data
	call modify_selector

	mov ax, es
	mov si, gdt_table.data2
	call modify_selector

	cli

	; Load a 32-bit segment descriptor table
	lgdt [gdt_desc]

	; Enter protected mode
	mov eax, cr0
	or al, 1
	mov cr0, eax

	; Setup the new segment descriptors
	; We are now in protected mode, but not for long.
	jmp dword 0x08:.set_cs
.set_cs:
	
	mov ax, 0x10
	mov ds, ax
	mov ax, 0x18
	mov es, ax
	mov ax, 0x20
	mov ss, ax

	; Exit protected mode with the descriptors intact.
	mov eax, cr0
	and al, 0xFE
	mov cr0, eax

	; Now put the normal real mode segments back in place.
	xchg bx, bx
	jmp 0:.set_cs_again
.set_cs_again:
	mov ss, dx
	mov ax, 0
	mov es, ax
	mov ds, ax
	sti
	
	call _main

bits 16

.finished:

	cli
	mov sp, [os_sp]
	mov ax, [os_ss]
	mov ss, ax
	sti
	
	ret

.heap_error:
	mov si, heap_errmsg
	call os_print_string
	ret

.no_parameters:
	mov dx, 1
	jmp .args_done
	

__Exit:
	; Handles Exit()
	; Exiting at any point is easy, just restore the saved stack and return
	jmp __start.finished
	

modify_selector:
	push ax
	shl ax, 4
	or [si + 2], ax
	pop ax
	shr ax, 12
	or [si + 4], al
	ret

section .data

os_ss				dw 0
os_sp				dw 0

heap_errmsg			db 'HEAP ERROR', 13, 10, 0

argv0				dw 0
param_array			times MAX_PARAMS + 1 dw 0
argc				dw 0

; GDT descriptor for entering unreal mode
gdt_desc:
	.size dw 39
	.offset dd 0x20000 + gdt_table

gdt_table:
	.empty		dq 0
	.code		db 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x9A, 0x8F, 0x00
	.data		db 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x92, 0xCF, 0x00
	.data2		db 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x92, 0xCF, 0x00
	.stack		db 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x92, 0xCF, 0x00
