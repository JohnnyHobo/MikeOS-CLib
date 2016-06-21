%macro OSCALL_STRING_LENGTH 0
	push si
	mov si, [bp + 4]
	mov dx, os_string_length
	call dx
	pop si
%endmacro

%macro OSCALL_FIND_CHAR_IN_STRING 0


	push si
	mov si, [bp + 6]
	mov al, [bp + 4]
	push bx
	mov ah, 0Eh
	mov bh, 0
	int 0x10
	pop bx
	mov dx, os_print_string
	;mov dx, os_find_char_in_string
	;call dx
	mov ax, si
	pop si
%endmacro

%macro OSCALL_STRING_REVERSE 0
	push si
	mov si, [bp + 4]
	mov dx, os_string_reverse
	call dx
	mov ax, si
	pop si
%endmacro

%macro OSCALL_STRING_CHARCHANGE 0
	push si
	push bx
	mov si, [bp + 8]
	mov al, [bp + 6]
	mov bl, [bp + 4]
	mov dx, os_string_charchange
	call dx
	pop bx
	pop si
%endmacro

%macro OSCALL_STRING_UPPERCASE 0
	mov ax, [bp + 4]
	mov dx, os_string_uppercase
	call dx
%endmacro

%macro OSCALL_STRING_LOWERCASE 0
	mov ax, [bp + 4]
	mov dx, os_string_lowercase
	call dx
%endmacro

