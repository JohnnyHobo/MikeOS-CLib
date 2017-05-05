#include <mikeos.h>

char *options = "Option A,Option B,Maybe C?,Okay then: D";
char *optch = "ABCD";
char *dumpstr = "Hello world\r\nNew line!";
char input_buf[256];

int main()
{
	char *filename;
	int i, x, y;

	os_get_cursor_pos(&y, &x);
	os_print_string("Text\r\nOver multiple lines!\r\n");
	os_move_cursor(y, x);
	os_print_string("Change that text!\r\n\r\n");

	os_get_cursor_pos(&y, &x);
	os_move_cursor(y, 40);
	os_print_horiz_line(SINGLE_LINE);
	os_print_horiz_line(DOUBLE_LINE);

	os_hide_cursor();
	os_wait_for_key();

	os_draw_block(RED_BG, 3, 4, 10, 7);
	os_wait_for_key();
	
	os_show_cursor();
	os_wait_for_key();

	os_print_string("Printing a letter: ");
	os_print_char('a');
	os_print_char('\r');
	os_print_char('\n');

	os_print_string("Hexadecimals: ");
	os_print_1hex(0x1234);
	os_print_space();
	os_print_2hex(0x1234);
	os_print_space();
	os_print_4hex(0x1234);
	os_wait_for_key();
	os_print_newline();

	os_print_string("Enter some text: ");
	os_input_string(input_buf, 20);
	os_print_newline();
	os_print_string("You entered: ");
	os_print_string(input_buf);
	os_wait_for_key();
	os_print_newline();

	os_print_string("Dumping String: ");
	os_print_string(dumpstr);
	os_print_string(" Result: ");
	os_dump_string(dumpstr);
	os_wait_for_key();
	os_print_newline();

	draw_interface();
	os_wait_for_key();

	draw_interface();
	filename = os_file_selector();
	draw_interface();
	os_move_cursor(10, 2);
	os_print_string("Filename is: ");
	os_print_string(filename);
	os_wait_for_key();

	draw_interface();
	i = os_list_dialog(options, "Select an option", "");

	draw_interface();
	os_move_cursor(10, 2);
	if (i == 0) {
		os_print_string("You cancelled the list dialog!");
	} else {
		os_print_string("You chose option: ");
		os_print_char(optch[i - 1]);
	}
	os_wait_for_key();

	draw_interface();
	os_input_dialog(input_buf, "Enter some text.");

	draw_interface();
	os_move_cursor(10, 2);
	os_print_string("You entered: ");
	os_print_string(input_buf);	
	
	os_print_newline();
	os_wait_for_key();

	draw_interface();
	os_dialog_box("=== Message ===", "This is a simple message dialog.",
			"Press <ENTER> to continue!", OKAY_DIALOG);
	draw_interface();
	os_wait_for_key();

	if (os_dialog_box("========= Another Option ==========",
			"This dialog allows you to cancel!",
			"Lets see what you pick!",
			OKAY_CANCEL_DIALOG) == OKAY_RESPONSE) {
		draw_interface();
		os_move_cursor(10, 2);
		os_print_string("You are okay! :-)");
	} else {
		draw_interface();
		os_move_cursor(10, 2);
		os_print_string("YOU ARE CANCEL! OMG!");
	}
	os_wait_for_key();
	os_clear_screen();

	return 0;
}


void draw_interface()
{
	os_clear_screen();
	os_draw_background("Dialog Test", "Here goes!", LIGHTBLUE_ON_BLUE);
}
	

