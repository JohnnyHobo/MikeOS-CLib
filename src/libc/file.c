#include "libc/file.h"

int fgetc(FILE *f)
{
	if (f->ibuf.data[f->ibuf.offset] == '\0' && f->read() == 0) {
		return EOF;
	} else {
		return f->ibuf.data[f->ibuf.offset++];
	}
}


int getc(FILE *f)
{
	return fgetc(f);
}


int getchar()
{
	return fgetc(stdin);
}


char *gets(char *str)
{
	int i, ch;

	for (i = 0; ; i++) {
		ch = fgetc(stdin);

		if (ch == '\n' || ch == EOF) {
			break;
		}

		str[i] = ch;
	}

	str[i] = '\0';

	return str;
}


char *fgets(char *str, int num, FILE *f)
{
	int i, ch;

	if (num < 1) return 0;

	for (i = 0; i < (num - 1); ) {
		ch = fgetc(f);

		if (ch == EOF) break;
		str[i++] = ch;
		if (ch == '\n') break;
	}

	str[i] = '\0';
	return str;
}


int fputc(int ch, FILE *f)
{
	return f->write(ch);
}


int putc(int ch, FILE *f)
{
	return fputc(ch, f);
}


int putchar(int ch)
{
	return fputc(ch, stdout);
}


int fputs(char *str, FILE *f)
{
	int i;

	for (i = 0; str[i] != '\0'; i++) {
		if (fputc(str[i], f) == EOF) {
			return EOF;
		}
	}

	return 0;
}


int puts(char *str)
{
	if (fputs(str, stdout) == EOF) {
		return EOF;
	}

	if (fputc('\n', stdout) == EOF) {
		return EOF;
	}

	return 0;
}

