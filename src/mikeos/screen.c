asm("%include 'mikedev.inc'");
asm("%include 'oscall/screen.asm'");

void os_print_string(const char *str)
{
	asm("OSCALL_PRINT_STRING");
}

void os_clear_screen()
{
	asm("OSCALL_CLEAR_SCREEN");
}

void os_move_cursor(int row, int col)
{
	asm("OSCALL_MOVE_CURSOR");
}

void os_get_cursor_pos(int *row, int *col)
{
	asm("OSCALL_GET_CURSOR_POS");
}

void os_print_horiz_line(int type)
{
	asm("OSCALL_PRINT_HORIZ_LINE");
}

void os_show_cursor()
{
	asm("OSCALL_SHOW_CURSOR");
}

void os_hide_cursor()
{
	asm("OSCALL_HIDE_CURSOR");
}

void os_draw_block(int colour, int x, int y, int width, int finish_y)
{
	asm("OSCALL_DRAW_BLOCK");
}

char *os_file_selector()
{
	asm("OSCALL_FILE_SELECTOR");
}

int os_list_dialog(char *list, char *help1, char *help2)
{
	asm("OSCALL_LIST_DIALOG");
}

void os_draw_background(char *top_text, char *bottom_text, int colour)
{
	asm("OSCALL_DRAW_BACKGROUND");
}

void os_print_newline()
{
	asm("OSCALL_PRINT_NEWLINE");
}

char *os_input_dialog(char *buffer, char *msg2)
{
	asm("OSCALL_INPUT_DIALOG");
}

int os_dialog_box(char *msg1, char *msg2, char *msg3, int type)
{
	asm("OSCALL_DIALOG_BOX");
}

void os_print_space()
{
	asm("OSCALL_PRINT_SPACE");
}

void os_print_digit(int digit)
{
	asm("OSCALL_PRINT_DIGIT");
}

void os_print_1hex(unsigned char value)
{
	asm("OSCALL_PRINT_1HEX");
}

void os_print_2hex(unsigned char value)
{
	asm("OSCALL_PRINT_2HEX");
}

void os_print_4hex(unsigned short value)
{
	asm("OSCALL_PRINT_4HEX");
}

void os_print_char(char ch)
{
	asm("OSCALL_PRINT_CHAR");
}

char *os_input_string(char *buffer, int max_bytes)
{
	asm("OSCALL_INPUT_STRING");
} 

