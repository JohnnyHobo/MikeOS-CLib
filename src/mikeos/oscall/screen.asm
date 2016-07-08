%macro OSCALL_PRINT_STRING 0
	push si
	mov si, [bp + 4]
	call os_print_string
	pop si
%endmacro

%macro OSCALL_CLEAR_SCREEN 0
	call os_clear_screen
%endmacro

%macro OSCALL_MOVE_CURSOR 0
	mov dh, [bp + 4]
	mov dl, [bp + 6]
	call os_move_cursor
%endmacro

%macro OSCALL_GET_CURSOR_POS 0
	push si
	call os_get_cursor_pos
	mov si, [bp + 4]
	mov [si], dh
	mov si, [bp + 6]
	mov [si], dl
	pop si
%endmacro
	
%macro OSCALL_PRINT_HORIZ_LINE 0
	call os_print_horiz_line
%endmacro

%macro OSCALL_SHOW_CURSOR 0
	call os_show_cursor
%endmacro

%macro OSCALL_HIDE_CURSOR 0
	call os_hide_cursor
%endmacro

%macro OSCALL_DRAW_BLOCK 0
	push bx
	push si
	push di

	mov bl, [bp + 4]
	mov dl, [bp + 6]
	mov dh, [bp + 8]
	mov si, [bp + 10]
	mov di, [bp + 12]
	call os_draw_block

	pop di
	pop si
	pop bx
%endmacro

%macro OSCALL_FILE_SELECTOR 0
	call os_file_selector
	jnc %%done

	mov ax, 0
%%done:
%endmacro

%macro OSCALL_LIST_DIALOG 0
	push bx
	mov ax, [bp + 4]
	mov bx, [bp + 6]
	mov cx, [bp + 8]
	call os_list_dialog
	pop bx
%endmacro

%macro OSCALL_DRAW_BACKGROUND 0
	push bx
	mov ax, [bp + 4]
	mov bx, [bp + 6]
	mov cx, [bp + 8]
	call os_draw_background
	pop bx
%endmacro

%macro OSCALL_PRINT_NEWLINE 0
	call os_print_newline
%endmacro

%macro OSCALL_INPUT_DIALOG 0
	push bx
	mov ax, [bp + 4]
	mov bx, [bp + 6]
	call os_input_dialog
	pop bx
%endmacro

%macro OSCALL_DIALOG_BOX 0
	push bx
	mov ax, [bp + 4]
	mov bx, [bp + 6]
	mov cx, [bp + 8]
	mov dx, [bp + 10]
	call os_dialog_box
	pop bx
%endmacro

%macro OSCALL_PRINT_SPACE 0
	call os_print_space
%endmacro

%macro OSCALL_PRINT_DIGIT 0
	mov ax, [bp + 4]
	call os_print_digit
%endmacro

%macro OSCALL_PRINT_1HEX 0
	mov al, [bp + 4]
	call os_print_1hex
%endmacro

%macro OSCALL_PRINT_2HEX 0
	mov al, [bp + 4]
	call os_print_2hex
%endmacro

%macro OSCALL_PRINT_4HEX 0
	mov ax, [bp + 4]
	call os_print_4hex
%endmacro

%macro OSCALL_INPUT_STRING 0
	mov ax, [bp + 4]
	mov bx, [bp + 6]
	call os_input_string
%endmacro

%macro OSCALL_PRINT_CHAR 0
	push bx
	mov ah, 0x0E
	mov al, [bp + 4]
	mov bh, 0
	int 0x10
	pop bx
%endmacro

