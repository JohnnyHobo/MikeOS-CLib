EXTERN copy_str_low
EXTERN lowmem_offset
EXTERN lowmem_start
EXTERN os_call

%macro START_API 0
	push ebp
	movzx ebp, sp

	push esi
	push edi
	
	mov esi, [dword lowmem_start]
	mov [dword lowmem_offset], esi
%endmacro

%macro END_API 0
	mov esi, [ebp - 8]
	mov edi, [ebp - 4]

	leave
	retf
%endmacro


%macro UMCALL 1
	section .text
	db 0x9A		; The far call instruction
	%%offset: dd %1	; The location to be called

	section .relot	; Add an entry on the relocation table for the target.
	dd %%offset

	section .text
%endmacro


%macro MOSCALL 1
	push word %1
	; Push the dataseg? Hmmm...
	call far [dword os_call]
%endmacro

%macro RELOC_STR 1
	push word [dword lowmem_offset]
	mov esi, [ebp + 8 + (4 * %1)]
	UMCALL copy_str_low
%endmacro
	
