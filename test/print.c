#include <mikeos.h>
#include <stdio.h>

int main()
{
	char *string = "qwerty";

	os_print_string("Native printing with API newline.");
	os_print_newline();

	os_print_string("Native printing with escape code newline.\r\n");

	os_print_string("Native character printing: ");
	os_print_char('a');
	os_print_char('\r');
	os_print_char('\n');

	fputs("libc - puts printing.\n", stdout);
	fputs("libc - putc characters: ", stdout);
	fputc('a', stdout);
	fputc('\n', stdout);

	printf("libc - printf printing.\n");
	printf("String substitution: \"%s\"\n", string);
	printf("Integer substitution: 8-bit:%d, 16-bit:%d, 32-bit: %d\n", 
			23, -4321, 1234567890);

	os_wait_for_key();
	return 0;
}

