bits 16

GLOBAL copy_str_low
GLOBAL lowmem_offset

section .text
copy_str_low:
	mov edi, [dword lowmem_offset]
	.next:
	a32 lodsb
	a32 stosb
	cmp al, 0
	jne .next
	mov [dword lowmem_offset], edi
	retf


section .data
align 4


lowmem_offset dd 0




