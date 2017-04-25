#include <stdio.h>

int readcons();
int writecons(int ch);
FILE console = {&readcons, &writecons};

int readcons()
{
	int key;
	key = os_wait_for_key() & 0x00FF;
	os_print_char(key);
	return key;
}

int writecons(int ch)
{
	if (ch == '\n') {
		os_print_newline();
	} else {
		os_print_char(ch);
	}

	return ch;
}

