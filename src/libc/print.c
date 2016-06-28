#include "mikeos/screen.h"

void dummy()
{
}

int printf(char *fmt, ...)
{
	int i = 0;
	int printed = 0;
	char *arg = (char*)&fmt + sizeof(char*);
	char *str;

	if (fmt[0] == '\0') {
		return 0;
	}

	do {
		if (fmt[i] == '\n') {
			os_print_newline();
			printed += 2;
			continue;
		} else if (fmt[i] != '%') {
			os_print_char(fmt[i]);
			printed++;
			continue;
		}

		switch (fmt[++i]) {
			case 'd':
			case 'i':
				str = os_sint_to_string(*(int*)arg);
				printed += os_string_length(str);
				os_print_string(str);
				arg += sizeof(int);
				break;

			case 'u':
				str = os_int_to_string(*(int*)arg);
				printed += os_string_length(str);
				os_print_string(str);
				arg += sizeof(int);
				break;

			case 'x':
			case 'X':
				os_print_4hex(*(int*)arg);
				printed += 4;
				arg += sizeof(int);
				break;

			case 'c':
				os_print_char(*arg);
				printed++;
				arg += sizeof(int);
				break;

			case 's':
				str = *(char**)arg;
				printed += os_string_length(str);
				os_print_string(str);
				arg += sizeof(char*);
				break;

			case 'p':
				os_print_string("0x");
				os_print_4hex(*(int*)arg);
				printed += 6;
				arg += sizeof(int);
				break;

			case 'n':
				*(int*)arg = printed;
				arg += sizeof(int*);
				break;

			case '%':
				os_print_char('%');
				printed++;
				break;
		}

	} while (fmt[++i]);

	return printed;
}
	
int putchar(int character)
{
	os_print_char(character);
	return character;
}

int puts(char *str)
{
	os_print_string(str);
	os_print_newline();
	return os_string_length(str);
}

char getchar()
{
	return os_wait_for_key() & 0x00FF;
}

char *gets(char *str)
{
	os_input_string(str, 256);
	os_print_newline();
	return str;
}


