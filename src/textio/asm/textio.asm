%define TEXTIO_USE_STATE_SAVE
%include 'lib/textio.asm'

%macro LIBCALL_TEXTIO_INIT 0
	call textio_init
%endmacro

%macro LIBCALL_TEXTIO_WRITE_CHAR 0
	mov al, [bp + 4]
	call textio_write_char
%endmacro

%macro LIBCALL_TEXTIO_READ_CHAR 0
	call textio_read_char
	
	push bx
	
	mov bx, [bp + 4]
	movzx dx, ah
	mov [bx], dx
	
	mov bx, [bp + 6]
	mov [bx], al
	
	pop bx
%endmacro

%macro LIBCALL_TEXTIO_SET_CHAR 0
	mov al, [bp + 4]
	mov dh, [bp + 6]
	mov dl, [bp + 8]
	call textio_set_char
%endmacro

%macro LIBCALL_TEXTIO_DRAW_HLINE 0
	push bx

	mov al, [bp + 4]
	mov bx, [bp + 6]
	mov dh, [bp + 8]
	mov dl, [bp + 10]
	call textio_draw_hline

	pop bx
%endmacro

%macro LIBCALL_TEXTIO_DRAW_VLINE 0
	push bx

	mov al, [bp + 4]
	mov bx, [bp + 6]
	mov dh, [bp + 8]
	mov dl, [bp + 10]
	call textio_draw_vline

	pop bx
%endmacro

%macro LIBCALL_TEXTIO_DRAW_BLOCK 0
	push bx

	mov al, [bp + 4]
	mov bh, [bp + 6]
	mov bl, [bp + 8]
	mov ch, [bp + 10]
	mov cl, [bp + 12]
	call textio_draw_block

	pop bx
%endmacro

%macro LIBCALL_TEXTIO_GRAB_AREA 0
	push bx
	push si

	mov bh, [bp + 4]
	mov bl, [bp + 6]
	mov ch, [bp + 8]
	mov cl, [bp + 10]
	mov si, [bp + 12]
	call textio_grab_area

	pop si
	pop bx
%endmacro

%macro LIBCALL_TEXTIO_RESTORE_AREA 0
	push bx
	push si

	mov bh, [bp + 4]
	mov bl, [bp + 6]
	mov ch, [bp + 8]
	mov cl, [bp + 10]
	mov si, [bp + 12]
	call textio_restore_area

	pop si
	pop bx
%endmacro

%macro LIBCALL_TEXTIO_SET_TEXT_COLOUR 0
	mov al, [bp + 4]
	call textio_set_text_colour
%endmacro

%macro LIBCALL_TEXTIO_GET_TEXT_COLOUR 0
	call textio_get_text_colour
	mov ah, 0
%endmacro


%macro LIBCALL_TEXTIO_SET_OUTPUT_PAGE 0
	mov al, [bp + 4]
	call textio_set_output_page
%endmacro


%macro LIBCALL_TEXTIO_GET_OUTPUT_PAGE 0
	call textio_get_output_page 
	mov ah, 0
%endmacro


%macro LIBCALL_TEXTIO_SET_VISIBLE_PAGE 0
	mov al, [bp + 4]
	call textio_set_visible_page
%endmacro


%macro LIBCALL_TEXTIO_GET_VISIBLE_PAGE 0
	call textio_get_visible_page 
	mov ah, 0
%endmacro


%macro LIBCALL_TEXTIO_PRINT_STRING 0
	push si
	
	mov si, [bp + 4]
	call textio_print_string
	
	pop si
%endmacro

%macro LIBCALL_TEXTIO_REVERSE_CURSOR 0
	call textio_reverse_cursor
%endmacro

%macro LIBCALL_TEXTIO_ADVANCE_CURSOR 0
	call textio_advance_cursor
%endmacro

%macro LIBCALL_TEXTIO_NEWLINE 0
	call textio_newline
%endmacro

%macro LIBCALL_TEXTIO_SET_CURSOR 0
	mov dh, [bp + 4]
	mov dl, [bp + 6]
	call textio_set_cursor
%endmacro

%macro LIBCALL_TEXTIO_GET_CURSOR 0
	push bx

	call textio_get_cursor
	
	mov bx, [bp + 4]
	movzx ax, dh
	mov [bx], ax
	
	mov bx, [bp + 6]
	movzx ax, dl
	mov [bx], ax
	
	pop bx
%endmacro

%macro LIBCALL_TEXTIO_SCROLL_DOWN 0
	mov cx, [bp + 4]
	call textio_scroll_down
%endmacro

%macro LIBCALL_TEXTIO_CLEAR_SCREEN 0
	call textio_clear_screen
%endmacro

%macro LIBCALL_TEXTIO_SET_SCREEN_LIMITS 0
	mov dh, [bp + 4]
	mov dl, [bp + 6]
	call textio_set_screen_limits
%endmacro


%macro LIBCALL_TEXTIO_GET_SCREEN_LIMITS 0
	push bx

	call textio_get_screen_limits

	mov bx, [bp + 4]
	movzx ax, dh
	mov [bx], ax

	mov bx, [bp + 6]
	movzx ax, dl
	mov [bx], ax

	pop bx
%endmacro


%macro LIBCALL_TEXTIO_CLONE_PAGE 0
	mov ah, [bp + 4]
	mov al, [bp + 6]
	call textio_clone_page
%endmacro


%macro LIBCALL_TEXTIO_SET_SCROLL_MODE 0
	mov al, [bp + 4]
	call textio_set_scroll_mode
%endmacro


%macro LIBCALL_TEXTIO_GET_SCROLL_MODE 0
	call textio_get_scroll_mode
	mov ah, 0
%endmacro


%macro LIBCALL_TEXTIO_SET_TEXT_MODE 0
	mov al, [bp + 4]
	call textio_set_text_mode
%endmacro


%macro LIBCALL_TEXTIO_GET_TEXT_MODE 0
	call textio_get_text_mode
	mov ah, 0
%endmacro


%macro LIBCALL_TEXTIO_GET_STATE_SIZE 0
	call textio_get_state_size
%endmacro


%macro LIBCALL_TEXTIO_SAVE_STATE 0
	push si

	mov si, [bp + 4]
	call textio_save_state

	pop si
%endmacro


%macro LIBCALL_TEXTIO_RESTORE_STATE 0
	push si

	mov si, [bp + 4]
	call textio_restore_state

	pop si
%endmacro

