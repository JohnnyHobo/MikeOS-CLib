bits 16

GLOBAL copy_str_low
GLOBAL copy_str_high
GLOBAL lowmem_offset
GLOBAL file_selector_buffer

EXTERN lowmem_segoffs

section .text
copy_str_low:
	movzx edi, word [dword lowmem_offset]
	add edi, [dword lowmem_segoffs]
	.next:
	a32 lodsb
	a32 stosb
	cmp al, 0
	jne .next
	sub edi, [dword lowmem_segoffs]
	mov [dword lowmem_offset], di
	retf


copy_str_high:
	push eax

	movzx esi, si
	add esi, [dword lowmem_segoffs]

	.next:
	a32 lodsb
	a32 stosb
	cmp al, 0
	jne .next

	pop eax
	retf


section .data
align 4


lowmem_offset dw 0




