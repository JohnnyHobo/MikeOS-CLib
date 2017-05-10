bits 16

%include 'mikedev.inc'
%include 'macros.inc'


; int os_get_api_version();
GLOBAL _os_get_api_version

_os_get_api_version:
	START_API

	MOSCALL os_get_api_version

	movzx eax, al
	END_API

	
; void os_pause(int time);
GLOBAL _os_pause

_os_pause:
	START_API

	mov ax, [ebp + 8]	; `time`
	MOSCALL os_pause

	END_API

	
; void os_fatal_error(char *error);
GLOBAL _os_fatal_error

_os_fatal_error:
	START_API

	RELOC_STR 0

	mov ax, [ebp - 10]	; `error`
	MOSCALL os_fatal_error

	END_API			; Is this even needed? It shouldn't return.

	
