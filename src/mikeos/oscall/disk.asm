%include '../common/carry.asm'

%macro OSCALL_GET_FILE_LIST 0
	mov ax, [bp+4]
	call os_get_file_list
%endmacro

%macro OSCALL_LOAD_FILE 0
	push si
	push bx

	mov ax, [bp+4]
	mov cx, [bp+8]
	call os_load_file
	CF_TO_AX
	mov si, [bp+6]
	mov [si], bx

	pop bx
	pop si
%endmacro

%macro OSCALL_WRITE_FILE 0
	push bx

	mov ax, [bp+4]
	mov bx, [bp+6]
	mov cx, [bp+8]
	call os_write_file
	CF_TO_AX

	pop bx
%endmacro

%macro OSCALL_FILE_EXISTS 0
	mov ax, [bp+4]
	call os_file_exists
	CF_TO_AX
%endmacro

%macro OSCALL_CREATE_FILE 0
	mov ax, [bp+4]
	call os_file_exists
	CF_TO_AX
%endmacro

%macro OSCALL_REMOVE_FILE 0
	mov ax, [bp+4]
	call os_file_exists
	CF_TO_AX
%endmacro

%macro OSCALL_RENAME_FILE 0
	push bx

	mov ax, [bp+4]
	mov bx, [bp+6]
	call os_rename_file
	CF_TO_AX

	pop bx
%endmacro

%macro OSCALL_GET_FILE_SIZE 0
	push si
	push bx

	mov ax, [bp+4]
	call os_get_file_size
	CF_TO_AX

	mov si, [bp+6]
	mov [si], bx

	pop bx
	pop si
%endmacro

