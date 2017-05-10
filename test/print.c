#include <mikeos.h>
#include <stdio.h>

int main()
{
	char *string = "qwerty";
	int numchars = 5;

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
	printf("Integer substitution: 8-bit:%d, 16-bit:%d, 32-bit:%d\n", 
			23, -4321, 1234567890);
	printf("Unsigned int substitution: 8-bit:%u, 16-bit:%u, 32-bit:%u\n",
			255U, 65535U, 4123456789U);

	printf("Literal percent: %%\n");
	printf("Hexadecimal numbers: lower:%x, upper:%X, large:%X\n",
			0xDEAD, 0xC0DE, 0x89ABCDEF);

	printf("Pointers: Fixed string:%p, local string:%p, main():%p\n%n",
			"abcdef", string, main, &numchars);

	printf("The number of characters in the previous line is: %d\n",
			numchars);

	os_wait_for_key();
	return 0;
}

