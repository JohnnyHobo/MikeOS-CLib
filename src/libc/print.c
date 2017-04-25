#include "mikeos/screen.h"
#include <stdarg.h>
#include "libc/file.h"
#include "libc/types.h"
#include <stdbool.h>

int putchar(int character)
{
	return putc(character, stdout);
}

int puts(char *str)
{
	if (fputs(str, stdout) == EOF) {
		return EOF;
	}

	if (fputc('\n', stdout) == EOF) {
		return EOF;
	} else {
		return 0;
	}
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

int print_string(int tofile, FILE *f, char *str, int limit, char *fmt, 
		va_list arg)
{
	int fmtcnt = 0;
	int count = 0;
	char ch, *str;
	char numstr[7];

	while (fmt[fmtcnt] != 0) {
		if (limit > 0 && count >= (limit - 1)) break;

		if (fmt[fmtcnt] != '%') {
			if (tofile) {
				fputc(fmt[fmtcnt], f);
			} else {
				str[count] = fmt[fmtcnt];
			}
			count++;
			fmtcnt++;
			continue;
		}

		if (fmt[++fmtcnt] == 0) break;
				
		if (limit > 0 && count >= (limit - 1)) break;

		switch (fmt[fmtcnt]) {
			case 'd':
			case 'i':
				str = sint_to_str(va_arg(arg, int), numstr);
				break;

			case 'u':
				str = uint_to_str(va_arg(arg, int), numstr);
				break;


			case 'x':
				str = hd_to_str(va_arg(arg, int), numstr);
				os_string_lowercase(str);
				break;

			case 'X':
				str = hd_to_str(va_arg(arg, int), numstr);
				break;

			case 'p':
				strcpy(numstr, "0x");
				str = hd_to_str(va_arg(arg, int), numstr + 2);
				break;

			case 'c':
				ch = va_arg(arg, char);
				break;

			case '%':
				ch = '%';
				break;

			case 's':
				str = va_arg(arg, char*);
				break;

			case 'n':
				*(va_arg(arg, int*)) = count;
				break;

		}

		switch (fmt[fmtcnt++]) {
			case 'd':
			case 'i':
			case 'u':
			case 'x':
			case 'X':
			case 'p':
			case 's':
				if (tofile) {
					fputs(str, f);
					count += strlen(str);
				} else {
					count += strncat(str, 
						str, limit - count - 1);
				}
				break;

			case 'c':
			case '%':
				if (tofile) {
					fputc(ch, f);
				} else {
					str[count] = ch;
				}

				count++;
				break;
		}

	}

	return count;
}

char *uint_to_str(unsigned int value, char *str)
{

	int count;

	do {
		str[count++] = value % 10 + '0';		
		value /= 10;
	} while (value > 0);
	str[count] = '\0';

	os_string_reverse(str);
	return str;
}


char *sint_to_str(int value, char *str)
{
	int count = 0;
	int sign = false;

	if (value < 0) {
		sign = true;
		value = -value;
		count++;
	}

	do {
		str[count++] = value % 10 + '0';		
		value /= 10;
	} while (value > 0);
	str[count] = '\0';

	if (!sign) {
		os_string_reverse(str);
	} else {
		os_string_reverse(str + 1);
		str[0] = '-';
	}

	return str;
}


char *hd_to_str(int value, char *str)
{
	int count;
	char *hexchar = "0123456789ABCDEF";

	do {
		str[count++] = hexchar[value % 16];		
		value /= 16;
	} while (value > 0);
	str[count] = '\0';

	os_string_reverse(str);
	return str;
}

	
char *num_to_str(int hassign, int base, int size, void *value, 
		char *str, int maxlen)
{
	char *num = value;
	int isneg;
	int len = 0;

	if (maxlen == 1) {
		str[0] = '\0';
		return str;
	}

	/* If negative, invert and remember sign */
	if (hassign && num[size - 1] & 0x80) {
		str[len++] = '-';
	}

	/* TODO */

	return 0;
}


int fputs(char *str, FILE *stream)
{
	int i;

	for (i = 0; str[i] != 0; i++) {
		/* if (stream->write(str[i]) == -1) return -1; */
		if (stream->write(str[i]) == -1) return -1;
	}

	return 0;
}


int fputc(int ch, FILE *stream)
{
	return stream->write(ch);
}


int putc(int ch, FILE *stream)
{
	return stream->write(ch);
}


int printf(char *format, ...)
{
	va_list args;

	va_start(args, format);
	print_string(true, stdout, 0, 0, format, args);
}

int vprintf(char *format, va_list args)
{
	return print_string(true, stdout, 0, 0, format, args);
}
	

int fprintf(FILE *stream, char *format, ...)
{

	va_list args;

	va_start(args, format);
	return print_string(true, stream, 0, 0, format, args);
}


int vfprintf(FILE *stream, char *format, va_list args)
{
	return print_string(true, stream, 0, 0, format, args);
}


int sprint(char *str, char *format, ...)
{
	va_list args;

	va_start(args, format);
	return print_string(false, 0, str, 0, format, args);
}


int vsprintf(char *str, char *format, va_list args)
{
	return print_string(false, 0, str, 0, format, args);
}


int snprintf(char *str, size_t n, char *format, ...)
{
	va_list args;

	va_start(args, format);
	return print_string(false, 0, str, n, format, args);
}


int vsnprintf(char *str, size_t n, char *format, va_list args)
{
	return print_string(false, 0, str, n, format, args);
}

