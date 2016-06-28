#ifndef MOSCLIB_HAS_STRING
#define MOSCLIB_HAS_STRING

#include "libc/memory.h"

#define NULL 0

int strlen(char *str);
char *strcpy(char *destination, char *source);
char *strcat(char *destination, char *source);

#endif

