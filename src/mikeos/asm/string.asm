%macro OSCALL_STRING_LENGTH 0
	mov ax, [bp + 4]
	call os_string_length
%endmacro

%macro OSCALL_FIND_CHAR_IN_STRING 0
	push si

	mov si, [bp + 4]
	mov al, [bp + 6]
	call os_find_char_in_string

	pop si
%endmacro

%macro OSCALL_STRING_REVERSE 0
	push si

	mov si, [bp + 4]
	call os_string_reverse
	mov ax, si

	pop si
%endmacro

%macro OSCALL_STRING_CHARCHANGE 0
	push si
	push bx

	mov si, [bp + 4]
	mov al, [bp + 6]
	mov bl, [bp + 8]
	call os_string_charchange
	mov ax, si

	pop bx
	pop si
%endmacro

%macro OSCALL_STRING_UPPERCASE 0
	mov ax, [bp + 4]
	call os_string_uppercase
%endmacro

%macro OSCALL_STRING_LOWERCASE 0
	mov ax, [bp + 4]
	call os_string_lowercase
%endmacro

%macro OSCALL_STRING_COPY 0
	push si
	push di

	mov si, [bp + 4]
	mov di, [bp + 6]
	call os_string_copy
	mov ax, di

	pop di
	pop si
%endmacro

%macro OSCALL_STRING_TRUNCATE 0
	push si

	mov si, [bp + 4]
	mov ax, [bp + 6]
	call os_string_truncate
	mov ax, si

	pop si
%endmacro

%macro OSCALL_STRING_JOIN 0
	push bx

	mov ax, [bp + 4]
	mov bx, [bp + 6]
	mov cx, [bp + 8]
	call os_string_join
	mov ax, cx

	pop bx
%endmacro

%macro OSCALL_STRING_CHOMP 0
	mov ax, [bp + 4]
	call os_string_chomp
%endmacro

%macro OSCALL_STRING_STRIP 0
	push si

	mov si, [bp + 4]
	mov al, [bp + 6]
	call os_string_strip
	mov ax, si

	pop si
%endmacro

%macro OSCALL_STRING_COMPARE 0
	push si
	push di

	mov si, [bp + 4]
	mov di, [bp + 6]
	call os_string_compare

	pop di
	pop si

	mov ah, 0
	setc al
%endmacro

%macro OSCALL_STRING_STRINCMP 0
	push si
	push di

	mov si, [bp + 4]
	mov di, [bp + 6]
	mov cl, [bp + 8]
	call os_string_strincmp

	pop di
	pop si

	mov ah, 0
	setc al
%endmacro

%macro OSCALL_STRING_PARSE 0
	push si
	push bx

	mov si, [bp + 4]
	call os_string_parse

	mov si, [bp + 6]
	mov [si], ax

	mov si, [bp + 8]
	mov [si], bx

	mov si, [bp + 10]
	mov [si], cx

	mov si, [bp + 12]
	mov [si], dx

	pop bx
	pop si
%endmacro

%macro OSCALL_STRING_TO_INT 0
	push si

	mov si, [bp + 4]
	call os_string_to_int

	pop si
%endmacro

%macro OSCALL_INT_TO_STRING 0
	mov ax, [bp + 4]
	call os_int_to_string
%endmacro

%macro OSCALL_SINT_TO_STRING 0
	mov ax, [bp + 4]
	call os_sint_to_string
%endmacro

%macro OSCALL_LONG_INT_TO_STRING 0
	push si
	push bx
	push di

	mov bx, [bp + 4]
	mov ax, [bx]
	mov dx, [bx + 2]

	mov bx, [bp + 6]
	mov di, [bp + 8]
	call os_long_int_to_string
	mov ax, di

	pop di
	pop bx
	pop si
%endmacro

%macro OSCALL_SET_TIME_FMT 0
	mov al, [bp + 4]
	call os_set_time_fmt
%endmacro


%macro OSCALL_GET_TIME_STRING 0
	push bx

	mov bx, [bp + 4]
	call os_get_time_string
	mov ax, bx

	pop bx
%endmacro


%macro OSCALL_SET_DATE_FMT 0
	mov ax, [bp + 4]
	call os_set_date_fmt
%endmacro


%macro OSCALL_GET_DATE_STRING 0
	push bx

	mov bx, [bp + 4]
	call os_get_date_string
	mov ax, bx

	pop bx
%endmacro

