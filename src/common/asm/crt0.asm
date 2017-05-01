%include '../mikeos/mikedev.inc'
%include 'loader.inc'
bits 16

%define MAX_PARAMS	16
%define STACK_SIZE	512

GLOBAL ___start__
GLOBAL ___Irq5Isr
GLOBAL __Exit
EXTERN _main

EXTERN memory_initialise
EXTERN __stop_alldata__


section .text

___Irq5Isr:
	retf

___start__:
	xchg bx, bx
	mov ax, [fs:LOADER_EXITPTR]
	mov [exitptr.offset], ax
	mov ax, [fs:LOADER_OS_CS]
	mov [exitptr.osseg], ax

.init_heap:
	; TODO: Call the new memory manager


.call_main:
	; Prepare to call the main function
	; It should look like this:
	; int main(int argc, char **argv);

	
	movzx eax, word [fs:LOADER_ARGV]
	mov ebx, [fs:LOADER_OS_DS]
	shl ebx, 4
	add eax, ebx
	push eax

	movzx eax, word [fs:LOADER_ARGC]
	push eax

	call _main

__Exit:
	; Handles Exit()

	cli
	mov ax, [fs:LOADER_OS_SS]
	mov ss, ax
	mov sp, [fs:LOADER_OS_SP]
	sti
	
	jmp far [exitptr]
	

modify_selector:
	push ax
	shl ax, 4
	or [si + 2], ax
	pop ax
	shr ax, 12
	or [si + 4], al
	ret


section .data

exitptr:
	.offset		dw 0
	.osseg		dw 0

