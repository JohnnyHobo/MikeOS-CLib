bits 16

%include 'mikedev.inc'
%include 'macros.inc'


; void os_run_basic(void *code, int size, char *parameters);
GLOBAL _os_run_basic

_os_run_basic:
	START_API

	RELOC_STR 2
	RELOC_DATA [ebp + 8], [ebp + 12]

	mov ax, [ebp - 14]		; `code` (local buffer)
	mov bx, [ebp + 12]		; `size`
	mov si, [ebp - 12]		; `parameters` (local buffer)
	MOSCALL os_run_basic

	END_API

	

