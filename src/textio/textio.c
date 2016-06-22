asm("%include 'asm/textio.asm'");

void textio_init()
{
	asm("LIBCALL_TEXTIO_INIT");
}

void textio_write_char(char ch)
{
	asm("LIBCALL_TEXTIO_WRITE_CHAR");
}

char textio_read_char()
{
	asm("LIBCALL_TEXTIO_READ_CHAR");
}

int textio_draw_char(int colour, char ch, int y, int x)
{
	asm("LIBCALL_TEXTIO_DRAW_CHAR");
}

void textio_draw_hline(int colour, char ch, int length, int start_y, int start_x)
{
	asm("LIBCALL_TEXTIO_DRAW_HLINE");
}

void textio_draw_vline(int colour, char ch, int length, int start_y, int start_x)
{
	asm("LIBCALL_TEXTIO_DRAW_VLINE");
}

void textio_draw_block(int colour, char ch, int start_y, int start_x, int finish_x, int finish_y)
{
	asm("LIBCALL_TEXTIO_DRAW_BLOCK");
}

void textio_grab_area(int start_y, int start_x, int finish_y, int finish_x, char *buffer)
{
	asm("LIBCALL_TEXTIO_GRAB_AREA");
}

void textio_restore_area(int start_y, int start_x, int finish_y, int finish_x, char *buffer)
{
	asm("LIBCALL_TEXTIO_RESTORE_AREA");
}

void textio_set_text_colour(int colour)
{
	asm("LIBCALL_TEXTIO_SET_TEXT_COLOUR");
}

void textio_set_output_page(int page)
{
	asm("LIBCALL_TEXTIO_SET_OUTPUT_PAGE");
}

void textio_set_visible_page(int page)
{
	asm("LIBCALL_TEXTIO_SET_VISIBLE_PAGE");
}

void textio_print_string(char *str)
{
	asm("LIBCALL_TEXTIO_PRINT_STRING");
}

void textio_reverse_cursor()
{
	asm("LIBCALL_TEXTIO_REVERSE_CURSOR");
}


void textio_advance_cursor()
{
	asm("LIBCALL_TEXTIO_ADVANCE_CURSOR");
}

void textio_newline()
{
	asm("LIBCALL_TEXTIO_NEWLINE");
}

void textio_set_cursor(int row, int column)
{
	asm("LIBCALL_TEXTIO_SET_CURSOR");
}

void textio_get_cursor(int *row, int *column)
{
	asm("LIBCALL_TEXTIO_GET_CURSOR");
}

void textio_scroll_down(int lines)
{
	asm("LIBCALL_TEXTIO_SCROLL_DOWN");
}

void textio_clear_screen()
{
	asm("LIBCALL_TEXTIO_CLEAR_SCREEN");
}

void textio_set_screen_limits(int row, int column)
{
	asm("LIBCALL_TEXTIO_SET_SCREEN_LIMITS");
}

