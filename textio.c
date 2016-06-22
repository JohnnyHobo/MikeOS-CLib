#include "mikeos.h"
#include "textio.h"

#define BOX_COLOUR 232
char *hello = "Hello World\n";

int main()
{
	textio_init();
	
	textio_set_text_colour(14);
	textio_print_string(hello);
	textio_print_string("Next line\n");
	os_wait_for_key();
	textio_draw_hline(BOX_COLOUR, '-', 30, 10, 31);
	os_wait_for_key();
	textio_draw_hline(BOX_COLOUR, '-', 30, 16, 31);
	os_wait_for_key();
	textio_draw_vline(BOX_COLOUR, '-', 5, 11, 30);
	os_wait_for_key();
	textio_draw_vline(BOX_COLOUR, '-', 5, 11, 60);
	os_wait_for_key();
	textio_draw_char(BOX_COLOUR, '+', 10, 30);
	os_wait_for_key();
	textio_draw_char(BOX_COLOUR, '+', 10, 60);
	os_wait_for_key();
	textio_draw_char(BOX_COLOUR, '+', 16, 30);
	os_wait_for_key();
	textio_draw_char(BOX_COLOUR, '+', 16, 60);
	os_wait_for_key();
	return 0;
}