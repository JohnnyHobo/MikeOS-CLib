bits 16

%include 'asm/textio.asm'
; glb textio_init : () void
section .text
	global	_textio_init
_textio_init:
	push	bp
	mov	bp, sp
	;sub	sp,          0
LIBCALL_TEXTIO_INIT
L1:
	leave
	ret

; glb textio_write_char : (
; prm     ch : char
;     ) void
section .text
	global	_textio_write_char
_textio_write_char:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     ch : (@4): char
LIBCALL_TEXTIO_WRITE_CHAR
L3:
	leave
	ret

; glb textio_read_char : () char
section .text
	global	_textio_read_char
_textio_read_char:
	push	bp
	mov	bp, sp
	;sub	sp,          0
LIBCALL_TEXTIO_READ_CHAR
L5:
	leave
	ret

; glb textio_draw_char : (
; prm     colour : int
; prm     ch : char
; prm     y : int
; prm     x : int
;     ) int
section .text
	global	_textio_draw_char
_textio_draw_char:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     colour : (@4): int
; loc     ch : (@6): char
; loc     y : (@8): int
; loc     x : (@10): int
LIBCALL_TEXTIO_DRAW_CHAR
L7:
	leave
	ret

; glb textio_draw_hline : (
; prm     colour : int
; prm     ch : char
; prm     length : int
; prm     start_y : int
; prm     start_x : int
;     ) void
section .text
	global	_textio_draw_hline
_textio_draw_hline:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     colour : (@4): int
; loc     ch : (@6): char
; loc     length : (@8): int
; loc     start_y : (@10): int
; loc     start_x : (@12): int
LIBCALL_TEXTIO_DRAW_HLINE
L9:
	leave
	ret

; glb textio_draw_vline : (
; prm     colour : int
; prm     ch : char
; prm     length : int
; prm     start_y : int
; prm     start_x : int
;     ) void
section .text
	global	_textio_draw_vline
_textio_draw_vline:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     colour : (@4): int
; loc     ch : (@6): char
; loc     length : (@8): int
; loc     start_y : (@10): int
; loc     start_x : (@12): int
LIBCALL_TEXTIO_DRAW_VLINE
L11:
	leave
	ret

; glb textio_draw_block : (
; prm     colour : int
; prm     ch : char
; prm     start_y : int
; prm     start_x : int
; prm     finish_x : int
; prm     finish_y : int
;     ) void
section .text
	global	_textio_draw_block
_textio_draw_block:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     colour : (@4): int
; loc     ch : (@6): char
; loc     start_y : (@8): int
; loc     start_x : (@10): int
; loc     finish_x : (@12): int
; loc     finish_y : (@14): int
LIBCALL_TEXTIO_DRAW_BLOCK
L13:
	leave
	ret

; glb textio_grab_area : (
; prm     start_y : int
; prm     start_x : int
; prm     finish_y : int
; prm     finish_x : int
; prm     buffer : * char
;     ) void
section .text
	global	_textio_grab_area
_textio_grab_area:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     start_y : (@4): int
; loc     start_x : (@6): int
; loc     finish_y : (@8): int
; loc     finish_x : (@10): int
; loc     buffer : (@12): * char
LIBCALL_TEXTIO_GRAB_AREA
L15:
	leave
	ret

; glb textio_restore_area : (
; prm     start_y : int
; prm     start_x : int
; prm     finish_y : int
; prm     finish_x : int
; prm     buffer : * char
;     ) void
section .text
	global	_textio_restore_area
_textio_restore_area:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     start_y : (@4): int
; loc     start_x : (@6): int
; loc     finish_y : (@8): int
; loc     finish_x : (@10): int
; loc     buffer : (@12): * char
LIBCALL_TEXTIO_RESTORE_AREA
L17:
	leave
	ret

; glb textio_set_text_colour : (
; prm     colour : int
;     ) void
section .text
	global	_textio_set_text_colour
_textio_set_text_colour:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     colour : (@4): int
LIBCALL_TEXTIO_SET_TEXT_COLOUR
L19:
	leave
	ret

; glb textio_set_output_page : (
; prm     page : int
;     ) void
section .text
	global	_textio_set_output_page
_textio_set_output_page:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     page : (@4): int
LIBCALL_TEXTIO_SET_OUTPUT_PAGE
L21:
	leave
	ret

; glb textio_set_visible_page : (
; prm     page : int
;     ) void
section .text
	global	_textio_set_visible_page
_textio_set_visible_page:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     page : (@4): int
LIBCALL_TEXTIO_SET_VISIBLE_PAGE
L23:
	leave
	ret

; glb textio_print_string : (
; prm     str : * char
;     ) void
section .text
	global	_textio_print_string
_textio_print_string:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     str : (@4): * char
LIBCALL_TEXTIO_PRINT_STRING
L25:
	leave
	ret

; glb textio_reverse_cursor : () void
section .text
	global	_textio_reverse_cursor
_textio_reverse_cursor:
	push	bp
	mov	bp, sp
	;sub	sp,          0
LIBCALL_TEXTIO_REVERSE_CURSOR
L27:
	leave
	ret

; glb textio_advance_cursor : () void
section .text
	global	_textio_advance_cursor
_textio_advance_cursor:
	push	bp
	mov	bp, sp
	;sub	sp,          0
LIBCALL_TEXTIO_ADVANCE_CURSOR
L29:
	leave
	ret

; glb textio_newline : () void
section .text
	global	_textio_newline
_textio_newline:
	push	bp
	mov	bp, sp
	;sub	sp,          0
LIBCALL_TEXTIO_NEWLINE
L31:
	leave
	ret

; glb textio_set_cursor : (
; prm     row : int
; prm     column : int
;     ) void
section .text
	global	_textio_set_cursor
_textio_set_cursor:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     row : (@4): int
; loc     column : (@6): int
LIBCALL_TEXTIO_SET_CURSOR
L33:
	leave
	ret

; glb textio_get_cursor : (
; prm     row : * int
; prm     column : * int
;     ) void
section .text
	global	_textio_get_cursor
_textio_get_cursor:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     row : (@4): * int
; loc     column : (@6): * int
LIBCALL_TEXTIO_GET_CURSOR
L35:
	leave
	ret

; glb textio_scroll_down : (
; prm     lines : int
;     ) void
section .text
	global	_textio_scroll_down
_textio_scroll_down:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     lines : (@4): int
LIBCALL_TEXTIO_SCROLL_DOWN
L37:
	leave
	ret

; glb textio_clear_screen : () void
section .text
	global	_textio_clear_screen
_textio_clear_screen:
	push	bp
	mov	bp, sp
	;sub	sp,          0
LIBCALL_TEXTIO_CLEAR_SCREEN
L39:
	leave
	ret

; glb textio_set_screen_limits : (
; prm     row : int
; prm     column : int
;     ) void
section .text
	global	_textio_set_screen_limits
_textio_set_screen_limits:
	push	bp
	mov	bp, sp
	;sub	sp,          0
; loc     row : (@4): int
; loc     column : (@6): int
LIBCALL_TEXTIO_SET_SCREEN_LIMITS
L41:
	leave
	ret



; Syntax/declaration table/stack:
; Bytes used: 915/15360


; Macro table:
; Macro __SMALLER_C__ = `0x0100`
; Macro __SMALLER_C_16__ = ``
; Macro __SMALLER_C_SCHAR__ = ``
; Bytes used: 63/5120


; Identifier table:
; Ident __floatsisf
; Ident __floatunsisf
; Ident __fixsfsi
; Ident __fixunssfsi
; Ident __addsf3
; Ident __subsf3
; Ident __negsf2
; Ident __mulsf3
; Ident __divsf3
; Ident __lesf2
; Ident __gesf2
; Ident textio_init
; Ident textio_write_char
; Ident ch
; Ident textio_read_char
; Ident textio_draw_char
; Ident colour
; Ident y
; Ident x
; Ident textio_draw_hline
; Ident length
; Ident start_y
; Ident start_x
; Ident textio_draw_vline
; Ident textio_draw_block
; Ident finish_x
; Ident finish_y
; Ident textio_grab_area
; Ident buffer
; Ident textio_restore_area
; Ident textio_set_text_colour
; Ident textio_set_output_page
; Ident page
; Ident textio_set_visible_page
; Ident textio_print_string
; Ident str
; Ident textio_reverse_cursor
; Ident textio_advance_cursor
; Ident textio_newline
; Ident textio_set_cursor
; Ident row
; Ident column
; Ident textio_get_cursor
; Ident textio_scroll_down
; Ident lines
; Ident textio_clear_screen
; Ident textio_set_screen_limits
; Bytes used: 649/5632

; Next label number: 43
; Compilation succeeded.
