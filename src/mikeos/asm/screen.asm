bits 16

%include 'mikedev.inc'
%include 'macros.inc'

GLOBAL _os_print_string

section .text

; OS Wrapper
; void os_print_string(const char *str)
_os_print_string:
	START_API

	RELOC_STR 0
	
	mov si, [ebp - 10]
	xchg bx, bx
	MOSCALL os_print_string

	END_API

