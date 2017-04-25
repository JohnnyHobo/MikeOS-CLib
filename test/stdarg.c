#include <stdarg.h>
#include <mikeos.h>
#include <stdio.h>
#include <stdlib.h>

int argfunc(char *format, ...);

int main()
{
	int i = 678;
	char ch = 'Z';

	argfunc("cicjd", '\n', 501, 'a', &i, &ch);
	exit(0);
}


int argfunc(char *format, ...)
{
	va_list al;
	int i;

	va_start(al, format);

	for (i = 0; format[i] != 0; i++) {
		switch (format[i]) {
			case 'i':
				printf("%d\n", va_arg(al, int));
				break;

			case 'j':
				printf("%d\n", *va_arg(al, int*));
				break;

			case 'c':
				printf("%c\n", va_arg(al, char));
				break;

			case 'd':
				printf("%c\n", *va_arg(al, char*));
		}
	}

	return i;
}

