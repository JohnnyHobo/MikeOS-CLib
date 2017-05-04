bits 16

%include 'mikedev.inc'
%include 'macros.inc'

section .text


; char *os_get_file_list(void *buffer);
GLOBAL _os_get_file_list

_os_get_file_list:
	START_API

	ALLOC_DATA 1024

	mov ax, [ebp - 10]
	MOSCALL os_get_file_list

	RESTORE_STR ax, [ebp + 8]
	mov eax, [ebp + 8]

	END_API

	
; int os_load_file(char *filename, void *buffer, int *size);
GLOBAL _os_load_file

_os_load_file:
	START_API
	push bx

	RELOC_STR 0
	ALLOC_DATA 30000

	mov ax, [ebp - 12]
	mov cx, [ebp - 14]
	MOSCALL os_load_file
	setnc dl

	RESTORE_DATA ax, 30000, [ebp + 12]

	mov esi, [ebp + 16]
	movzx eax, bx
	mov [esi], eax

	movzx eax, dl

	mov bx, [ebp - 10]
	END_API

	
; int os_write_file(char *filename, void *buffer, int size);
GLOBAL _os_write_file

_os_write_file:
	START_API
	push bx

	RELOC_STR 0
	RELOC_DATA [ebp + 12], [ebp + 16]

	mov ax, [ebp - 12]	; `filename` (local buffer)
	mov bx, [ebp - 14]	; `buffer` (local buffer)
	mov cx, [ebp + 16]	; `size`
	MOSCALL os_write_file
	
	setnc al
	movzx eax, al

	mov bx, [ebp - 10]
	END_API

	
; int os_file_exists(char *filename);
GLOBAL _os_file_exists

_os_file_exists:
	START_API

	RELOC_STR 0

	mov ax, [ebp - 10]
	MOSCALL os_file_exists

	setnc al
	movzx eax, al
	END_API
	

; int os_create_file(char *filename);
GLOBAL _os_create_file

_os_create_file:
	START_API

	RELOC_STR 0

	mov ax, [ebp - 10]
	MOSCALL os_create_file

	setnc al
	movzx eax, al
	END_API

	
; int os_remove_file(char *filename);
GLOBAL _os_remove_file

_os_remove_file:
	START_API

	RELOC_STR 0

	mov ax, [ebp - 10]
	MOSCALL os_remove_file

	setnc al
	movzx eax, al
	END_API

	
; int os_rename_file(char *oldname, char *newname);
GLOBAL _os_rename_file

_os_rename_file:
	START_API
	push bx

	RELOC_STR 0
	RELOC_STR 1

	mov ax, [ebp - 12]
	mov bx, [ebp - 14]
	MOSCALL os_rename_file

	setnc al
	movzx eax, al

	mov bx, [ebp - 10]
	END_API

	
; int os_get_file_size(char *filename, int *size);
GLOBAL _os_get_file_size

_os_get_file_size:
	START_API
	push bx

	RELOC_STR 0
	
	mov ax, [ebp - 12]
	MOSCALL os_get_file_size
	setnc dl

	mov esi, [ebp + 12]
	movzx eax, bx
	mov [esi], eax

	movzx eax, al

	mov bx, [ebp - 10]
	END_API

	
