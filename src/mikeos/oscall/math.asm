%macro OSCALL_BCD_TO_INT 0
	mov al, [bp+4]
	call os_bcd_to_int
%endmacro

%macro OSCALL_LONG_INT_NEGATE 0
	push si
	push di

	mov si, [bp+4]
	mov di, [bp+6]

	mov ax, [si]
	mov dx, [si+2]
	call os_long_int_negate
	mov [di], ax
	mov [di+2], dx

	pop di
	pop si
%endmacro

%macro OSCALL_GET_RANDOM 0
	push bx
	mov ax, [bp+4]
	mov bx, [bp+6]
	call os_get_random
	pop bx
	mov ax, cx
%endmacro
