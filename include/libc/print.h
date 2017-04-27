#ifndef MOSCLIB_HAS_PRINT
#define MOSCLIB_HAS_PRINT

#include <stdarg.h>
#include "libc/file.h"
#include "libc/types.h"

int printf(char *fmt, ...);
int vprintf(char *format, va_list args);
int fprintf(FILE *stream, char *format, ...);
int vfprintf(FILE *stream, char *format, va_list args);
int sprint(char *str, char *format, ...);
int vsprintf(char *str, char *format, va_list args);
int snprintf(char *str, size_t n, char *format, ...);
int vsnprintf(char *str, size_t n, char *format, va_list args);

#endif
