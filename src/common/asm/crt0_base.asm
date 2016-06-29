%include '../mikeos/mikedev.inc'
bits 16

%define MAX_PARAMS	16
%define STACK_SIZE	512

GLOBAL __start
GLOBAL __Exit
EXTERN _main

%ifdef MOSCLIB_USE_MM
EXTERN memory_initialise
EXTERN __stop_alldata__
%endif


section .text

; The memory layout should look like this:
; 0x0000			OS Kernel
; 0x8000			Binary Load Point
; 0x8000 + Binary Size		Heap Space
; 0x10000 - Stack Size		Stack Space

; Programs should use the heap to store any data

__start:
	; Program start routine --- called directly by the OS

%ifdef MOSCLIB_USE_PARAMS
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
	je .init_heap

	inc dx
	mov si, di
	loop .get_parameter
%endif

%ifdef MOSCLIB_USE_MM

.init_heap:
	; Setup the heap after the end of the program data
	mov si, __stop_alldata__
	mov ax, si
	neg ax
	sub ax, STACK_SIZE	; Do not include stack space in the heap

	call memory_initialise
	jc .heap_error
%endif
	
%ifdef MOSCLIB_USE_ALTSTACK
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
%endif

%ifdef MOSCLIB_USE_PARAMS
	; Now call the main function
	; It should look like this:
	; int main(int argc, char **argv);

	; MikeOS does not pass the program name as a parameter,
	; so this is non-standard.
	mov bx, param_array
	push bx
	push dx
%endif
	call _main

.finished:

%ifdef MOSCLIB_USE_ALTSTACK
	cli
	mov sp, [os_sp]
	mov ax, [os_ss]
	mov ss, ax
	sti
%endif
	
	ret

%ifdef MOSCLIB_USE_MM
.heap_error:
	mov si, heap_errmsg
	call os_print_string
	ret
%endif

%ifdef MOSCLIB_USE_PARAMS
.no_parameters:
	mov dx, 0
	mov word [param_array], 0
	jmp .init_heap
%endif
	

__Exit:
	; Handles Exit()
	; Exiting at any point is easy, just restore the saved stack and return
	jmp __start.finished
	

section .data

%ifdef MOSCLIB_USE_ALTSTACK
os_ss				dw 0
os_sp				dw 0
%endif

%ifdef MOSCLIB_USE_MM
heap_errmsg			db 'HEAP ERROR', 13, 10, 0
%endif

%ifdef MOSCLIB_USE_PARAMS
param_array			times MAX_PARAMS dw 0
%endif
