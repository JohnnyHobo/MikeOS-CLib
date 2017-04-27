#include <stdio.h>

int readcons();
int writecons(int ch);
char inbuf[257] = {'\0'};
FILE console = {&readcons, &writecons, {257, 0, inbuf}};

/* May need 256 bytes for older versions of MikeOS */
int readcons()
{
	os_input_string(console.ibuf.data, 256);
	os_print_newline();
	console.ibuf.offset = 0;
	strcat(console.ibuf.data, "\n");
	return strlen(console.ibuf.data);
}

/* Unbuffered for now. */
int writecons(int ch)
{
	if (ch == '\n') {
		os_print_newline();
	} else {
		os_print_char(ch);
	}

	return ch;
}

