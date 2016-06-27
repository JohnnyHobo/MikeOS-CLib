%macro OSCALL_BCD_TO_INT 0
	mov al, [bp+4]
	call os_bcd_to_int
%endmacro

%macro OSCALL_LONG_INT_NEGATE 0
	push bx

	mov bx, [bp + 4]

	mov ax, [bx]
	mov dx, [bx + 2]
	call os_long_int_negate
	mov [bx], ax
	mov [bx + 2], dx

	pop bx
%endmacro

%macro OSCALL_GET_RANDOM 0
	push bx
	mov ax, [bp+4]
	mov bx, [bp+6]
	call os_get_random
	pop bx
	mov ax, cx
%endmacro
