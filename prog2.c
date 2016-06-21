#include "mikeos.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char **argv)
{
	int x = 0;
	int y = 0;
	int key;
	
	do {
		os_clear_screen();
		os_move_cursor(y, x);
		os_print_char('X');
		os_move_cursor(y, x);
		key = os_wait_for_key();
		if (key == UP_KEY && y > 0) y--;
		if (key == DOWN_KEY && y < 24) y++;
		if (key == LEFT_KEY && x > 0) x--;
		if (key == RIGHT_KEY && x < 79) x++;
	} while (key != ESC_KEY);

	os_clear_screen();
	
	return 0;
}

