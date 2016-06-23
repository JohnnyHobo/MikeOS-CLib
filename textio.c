#include "mikeos.h"
#include "textio.h"

#define BOX_COLOUR 47
char *hello = "Hello World\n";

int main()
{
	int row, col;
	
	textio_init();
	
	textio_set_text_colour(14);
	textio_set_output_page(2);
	textio_clear_screen();
	
	textio_print_string(hello);
	textio_print_string("Next line\n");
	
	textio_set_text_colour(BOX_COLOUR);
	textio_draw_block(' ', 10, 30, 16, 61);
	textio_draw_hline('-', 30, 10, 31);
	textio_draw_hline('-', 30, 16, 31);
	textio_draw_vline('|', 4, 11, 30);
	textio_draw_vline('|', 4, 11, 61);
	textio_set_char('+', 10, 30);
	textio_set_char('+', 10, 61);
	textio_set_char('+', 16, 30);
	textio_set_char('+', 16, 61);
	
	textio_set_output_page(0);
	textio_set_text_colour(7);
	textio_print_string("Drawing complete.");
	textio_reverse_cursor();
	os_wait_for_key();
	
	textio_set_visible_page(2);
	os_wait_for_key();
	textio_set_visible_page(0);
	textio_newline();
	
	return 0;
}
