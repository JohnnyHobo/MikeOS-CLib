%macro OSCALL_GET_FILE_LIST 0
	mov ax, [bp + 4]
	call os_get_file_list
%endmacro

%macro OSCALL_LOAD_FILE 0
	push si
	push bx

	mov ax, [bp + 4]
	mov cx, [bp + 6]
	call os_load_file
	
	mov ah, 0
	setnc al

	mov si, [bp + 8]
	mov [si], bx

	pop bx
	pop si
%endmacro

%macro OSCALL_WRITE_FILE 0
	push bx

	mov ax, [bp + 4]
	mov bx, [bp + 6]
	mov cx, [bp + 8]
	call os_write_file

	mov ah, 0
	setnc al

	pop bx
%endmacro

%macro OSCALL_FILE_EXISTS 0
	mov ax, [bp + 4]
	call os_file_exists

	mov ah, 0
	setnc al
%endmacro

%macro OSCALL_CREATE_FILE 0
	mov ax, [bp + 4]
	call os_file_exists

	mov ah, 0
	setnc al
%endmacro

%macro OSCALL_REMOVE_FILE 0
	mov ax, [bp + 4]
	call os_file_exists

	mov ah, 0
	setnc al
%endmacro

%macro OSCALL_RENAME_FILE 0
	push bx

	mov ax, [bp + 4]
	mov bx, [bp + 6]
	call os_rename_file

	mov ah, 0
	setnc al

	pop bx
%endmacro

%macro OSCALL_GET_FILE_SIZE 0
	push si
	push bx

	mov ax, [bp + 4]
	call os_get_file_size

	mov ah, 0
	setnc al

	mov si, [bp + 6]
	mov [si], bx

	pop bx
	pop si
%endmacro

