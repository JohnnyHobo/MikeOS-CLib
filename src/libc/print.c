#include <stdbool.h>
#include <stdarg.h>

#include "mikeos/screen.h"
#include "libc/file.h"
#include "libc/types.h"
#include "common/minmax.h"

int print_string(int tofile, FILE *f, char *str, int limit, char *fmt, 
		va_list arg)
{
	int fmtcnt = 0;
	int count = 0;
	char ch, *s;
	char numstr[7];

	if (!tofile && str) str[0] = '\0';

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
				s = sint_to_str(va_arg(arg, int), numstr);
				break;

			case 'u':
				s = uint_to_str(va_arg(arg, int), numstr);
				break;


			case 'x':
				s = hd_to_str(va_arg(arg, int), numstr);
				os_string_lowercase(s);
				break;

			case 'X':
				s = hd_to_str(va_arg(arg, int), numstr);
				break;

			case 'p':
				strcpy(numstr, "0x");
				s = hd_to_str(va_arg(arg, int), numstr + 2);
				break;

			case 'c':
				ch = va_arg(arg, char);
				break;

			case '%':
				ch = '%';
				break;

			case 's':
				s = va_arg(arg, char*);
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
					fputs(s, f);
					count += strlen(s);
				} else if (str) {
					str[count] = '\0';
					strncat(str, s, limit - count - 1);
					count = strlen(str);
				} else {
					count += min(limit - count - 1, 
							strlen(str));
				}
				break;

			case 'c':
			case '%':
				if (tofile && str) {
					fputc(ch, f);
				} else {
					str[count] = ch;
				}

				count++;
				break;
		}

	}

	if (!tofile && str) str[count] = '\0';

	return count;
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


int sprintf(char *str, char *format, ...)
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

