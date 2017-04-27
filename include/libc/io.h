#ifndef MOSCLIB_HAS_IOFUNC
#define MOSCLIB_HAS_IOFUNC

#include "libc/file.h"

int fgetc(FILE *f);
int getc(FILE *f);
int getchar();
char *gets(char *str);
char *fgets(char *str, int num, FILE *f);
int fputc(int ch, FILE *f);
int putc(int ch, FILE *f);
int putchar(int ch);
int fputs(char *str, FILE *f);
int puts(char *str);

#endif

