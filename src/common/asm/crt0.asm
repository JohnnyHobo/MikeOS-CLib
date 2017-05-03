%include '../mikeos/mikedev.inc'
%include 'loader.inc'
bits 16

%define MAX_PARAMS	16
%define STACK_SIZE	512

GLOBAL ___start__
GLOBAL ___Irq5Isr
GLOBAL __Exit
GLOBAL os_call
GLOBAL os_ds
GLOBAL lowmem_start


EXTERN _main
EXTERN memory_initialise


section .text

___Irq5Isr:
	retf

___start__:
	movzx ebp, sp
	mov esi, [ebp + 4]

	mov [dword os_data], esi

	mov ax, [esi + LOADER_OS_EXIT]
	mov [dword os_exit], ax
	mov ax, [esi + LOADER_OS_CALL]
	mov [dword os_call], ax

	mov ax, [esi + LOADER_OS_CS]
	mov [dword os_exit + 2], ax
	mov [dword os_call + 2], ax

	mov ax, [esi + LOADER_OS_DS]
	mov [dword os_ds], ax

.init_heap:
	movzx eax, word [esi + LOADER_OS_DS]
	shl eax, 4
	movzx ebx, word [esi + LOADER_LOWMEM_START]
	add eax, ebx
	mov [dword lowmem_start], eax

	; TODO: Call the new memory manager


.call_main:
	; Prepare to call the main function
	; It should look like this:
	; int main(int argc, char **argv);

	
	movzx eax, word [esi + LOADER_ARGV]
	movzx ebx, word [esi + LOADER_OS_DS]
	shl ebx, 4
	add eax, ebx
	push eax

	movzx eax, word [esi + LOADER_ARGC]
	push eax

	db 0x9A		; 0x9A = call instruction
section .relot
	dd main_addr
section .text
main_addr:	dd _main	; _main is the address to relocate.


; Handles _Exit()
__Exit:
	mov esi, [dword os_data]
	mov ax, [esi + LOADER_OS_SS]

	cli
	mov ss, ax
	mov sp, [esi + LOADER_OS_SP]
	sti
	
	jmp far [dword os_exit]
	

section .data
align 4

os_data			dd 0
os_exit			dd 0
os_call			dd 0
lowmem_start		dd 0
os_ds			dw 0


