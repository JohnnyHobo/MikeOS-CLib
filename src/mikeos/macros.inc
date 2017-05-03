%ifndef MOSCLIB_HAS_MIKEOS_MACROS
%define MOSCLIB_HAS_MIKEOS_MACROS

%include '../common/macros.inc'

EXTERN copy_str_low
EXTERN copy_str_high
EXTERN lowmem_offset
EXTERN lowmem_start
EXTERN os_call
EXTERN os_ds
EXTERN file_selector_buffer


%macro START_API 0
	push ebp
	movzx ebp, sp

	push esi
	push edi
	
	mov si, [dword lowmem_start]
	mov [dword lowmem_offset], si
%endmacro


%macro END_API 0
	mov esi, [ebp - 8]
	mov edi, [ebp - 4]

	o32 leave
	retf
%endmacro


%macro MOSCALL 1
	push word %1
	push word [dword os_ds]
	call far [dword os_call]
%endmacro


%macro RELOC_STR 1
	push word [dword lowmem_offset]
	mov esi, [ebp + 8 + (4 * %1)]
	UMCALL copy_str_low
%endmacro


%macro ALLOC_DATA 1
	push word [dword lowmem_offset]
	add word [dword lowmem_offset], %1
%endmacro

	
%macro RESTORE_STR 2
	push esi
	push edi

	mov si, %1
	mov edi, %2
	UMCALL copy_str_high

	pop edi
	pop esi
%endmacro


%macro RESTORE_DATA 3
	push esi
	push edi
	push ecx

	movzx esi, word %1
	add esi, [dword lowmem_segoffs]
	mov edi, %3
	mov ecx, %2
	xchg bx, bx
	rep a32 movsb

	pop ecx
	pop edi
	pop esi
%endmacro
	

%endif	
