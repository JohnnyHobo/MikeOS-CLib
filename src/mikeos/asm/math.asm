bits 16

%include 'mikedev.inc'
%include 'macros.inc'

section .text

; int os_bcd_to_int(char bcd);
GLOBAL _os_bcd_to_int

_os_bcd_to_int:
	START_API

	mov al, [ebp + 8]	; `bcd`
	MOSCALL os_bcd_to_int

	movzx eax, ax
	END_API

	
; long os_long_int_negate(long value);
GLOBAL _os_long_int_negate

_os_long_int_negate:
	START_API

	mov ax, [ebp + 8]	; `value` (lower half)
	mov dx, [ebp + 10]	; `value` (higher half)
	MOSCALL os_long_int_negate

	movzx eax, ax
	shl eax, 16
	movzx edx, dx
	add eax, edx

	END_API

	
; int os_get_random(short min, short max);
GLOBAL _os_get_random

_os_get_random:
	START_API
	push bx

	mov ax, [ebp + 8]	; `min`
	mov bx, [ebp + 12]	; `max`
	MOSCALL os_get_random
	movsx eax, cx

	mov bx, [ebp - 10]
	END_API

	

