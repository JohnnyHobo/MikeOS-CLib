; OS Wrapper
; void os_print_string(const char *str)
; void os_clear_screen()
; void os_move_cursor()
; void os_print_horiz_line(int type)
; void os_show_cursor()
; void os_hide_cursor();
; void os_draw_block(int colour, int x, int y, int width, int finish_y);
; char *filename = os_file_selector();
; int option_number = os_list_dialog(char *list, char *help1, char *help2);
; void os_draw_background(char *top_text, char *bottom_text, int colour);
; void os_print_newline();
; char *input_text = os_input_dialog(char *buffer, char *msg);
; int result = os_dialog_box(char *msg1, char *msg2, char *msg3, int type);
; void os_print_space();
; void os_dump_string(char *str);
; void os_print_digit(int digit);
; void os_print_1hex(unsigned char value);
; void os_print_2hex(unsigned char value);
; void os_print_4hex(unsigned short value);
; void os_print_char(char value);
; char *os_input_string(char *buffer, int max_bytes);
bits 16

%include 'mikedev.inc'
%include 'macros.inc'

section .text

; OS Wrapper
; void os_print_string(const char *str)
GLOBAL _os_print_string

_os_print_string:
	START_API

	RELOC_STR 0
	
	mov si, [ebp - 10]
	MOSCALL os_print_string

	END_API


; void os_clear_screen()
GLOBAL _os_clear_screen

_os_clear_screen:
	START_API

	MOSCALL os_clear_screen

	END_API


; void os_move_cursor()
GLOBAL _os_move_cursor

_os_move_cursor:
	START_API

	mov dh, [ebp + 8]
	mov dl, [ebp + 12]
	MOSCALL os_move_cursor

	END_API


; void os_get_cursor_pos(int *row, int *col)
GLOBAL _os_get_cursor_pos

_os_get_cursor_pos:
	START_API

	MOSCALL os_get_cursor_pos
	mov esi, [ebp + 8]
	movzx eax, dh
	mov [esi], eax

	mov esi, [ebp + 12]
	movzx eax, dl
	mov [esi], eax

	END_API


; void os_print_horiz_line(int type)
GLOBAL _os_print_horiz_line

_os_print_horiz_line:
	START_API

	mov ax, [ebp + 8]
	MOSCALL os_print_horiz_line

	END_API


; void os_show_cursor()
GLOBAL _os_show_cursor

_os_show_cursor:
	START_API

	MOSCALL os_show_cursor	

	END_API

	

; void os_hide_cursor();
GLOBAL _os_hide_cursor

_os_hide_cursor:
	START_API

	MOSCALL os_hide_cursor

	END_API

	
; void os_draw_block(int colour, int x, int y, int width, int finish_y);
GLOBAL _os_draw_block

_os_draw_block:
	START_API

	push bx

	mov bl, [ebp + 8]
	mov dl, [ebp + 12]
	mov dh, [ebp + 16]
	mov si, [ebp + 20]
	mov di, [ebp + 24]
	MOSCALL os_draw_block

	mov bx, [ebp - 10]

	END_API

	
; char *filename = os_file_selector();
GLOBAL _os_file_selector

_os_file_selector:
	START_API

	MOSCALL os_file_selector
	
	RESTORE_STR ax, file_selector_buffer
	mov eax, file_selector_buffer

	END_API

	
; int option_number = os_list_dialog(char *list, char *help1, char *help2);
GLOBAL _os_list_dialog

_os_list_dialog:
	START_API

	RELOC_STR 0
	RELOC_STR 1
	RELOC_STR 2

	mov ax, [ebp - 10]
	mov bx, [ebp - 12]
	mov cx, [ebp - 14]
	MOSCALL os_list_dialog

	jc .esc_pressed

	movzx eax, ax
	END_API

.esc_pressed:
	mov eax, 0
	END_API

	
; void os_draw_background(char *top_text, char *bottom_text, int colour);
GLOBAL _os_draw_background

_os_draw_background:
	START_API
	push bx

	RELOC_STR 0
	RELOC_STR 1

	mov ax, [ebp - 12]
	mov bx, [ebp - 14]
	mov cx, [ebp + 16]
	MOSCALL os_draw_background

	mov bx, [ebp - 10]
	END_API

	
; void os_print_newline();
GLOBAL _os_print_newline

_os_print_newline:
	START_API

	MOSCALL os_print_newline

	END_API

	
; char *input_text = os_input_dialog(char *buffer, char *msg);
GLOBAL _os_input_dialog

_os_input_dialog:
	START_API
	push bx

	ALLOC_DATA 256
	RELOC_STR 1
	
	mov ax, [ebp - 12]
	mov bx, [ebp - 14]
	MOSCALL os_input_dialog

	RESTORE_STR ax, [ebp + 8]
	mov eax, [ebp + 8]

	mov bx, [ebp - 10]
	END_API

	
;enum DIALOG_RESPONSE os_dialog_box(char *msg1, char *msg2, char *msg3, 
;		enum DIALOG_TYPE type);
GLOBAL _os_dialog_box

_os_dialog_box:
	START_API
	push bx

	RELOC_STR 0
	RELOC_STR 1
	RELOC_STR 2

	mov ax, [ebp - 12]
	mov bx, [ebp - 14]
	mov cx, [ebp - 16]
	mov dx, [ebp + 20]
	MOSCALL os_dialog_box
	movzx eax, ax

	mov bx, [ebp - 10]
	END_API

	
; void os_print_space();
GLOBAL _os_print_space

_os_print_space:
	START_API

	MOSCALL os_print_space

	END_API

	
; void os_dump_string(char *str);
GLOBAL _os_dump_string

_os_dump_string:
	START_API

	RELOC_STR 0

	mov si, [ebp - 10]
	MOSCALL os_dump_string

	END_API

	
; void os_print_digit(int digit);
GLOBAL _os_print_digit

_os_print_digit:
	START_API

	mov ax, [ebp + 8]
	MOSCALL os_print_digit

	END_API

	
; void os_print_1hex(unsigned char value);
GLOBAL _os_print_1hex

_os_print_1hex:
	START_API

	mov al, [ebp + 8]
	MOSCALL os_print_1hex

	END_API

	
; void os_print_2hex(unsigned char value);
GLOBAL _os_print_2hex

_os_print_2hex:
	START_API

	mov al, [ebp + 8]
	MOSCALL os_print_2hex

	END_API

	
; void os_print_4hex(unsigned short value);
GLOBAL _os_print_4hex

_os_print_4hex:
	START_API

	mov ax, [ebp + 8]
	MOSCALL os_print_4hex

	END_API

	
; void os_print_char(char value);
GLOBAL _os_print_char

_os_print_char:
	START_API

	push bx

	mov ah, 0x0E
	mov al, [ebp + 8]
	mov bh, 0
	int 0x10

	mov bx, [ebp - 10]

	END_API

	
; char *os_input_string(char *buffer, int max_bytes);
GLOBAL _os_input_string

_os_input_string:
	START_API
	push bx

	ALLOC_DATA 256

	mov ax, [ebp - 12]
	mov bx, [ebp + 12]	
	MOSCALL os_input_string

	RESTORE_STR ax, [ebp + 8]

	movzx eax, ax

	mov bx, [ebp - 10]
	END_API

section .bss
	file_selector_buffer 	resb 13 
