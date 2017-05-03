bits 16

%include 'mikedev.inc'
%include 'macros.inc'

section .text

; short keycode = os_check_for_key();
GLOBAL _os_check_for_key

_os_check_for_key:
	START_API

	MOSCALL os_check_for_key

	END_API

	
; short keycode = os_wait_for_key();
GLOBAL _os_wait_for_key

_os_wait_for_key:
	START_API

	MOSCALL os_wait_for_key

	END_API

	
