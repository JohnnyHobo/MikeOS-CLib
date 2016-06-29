#ifndef MOSCLIB_HAS_STRING
#define MOSCLIB_HAS_STRING

#include "libc/memory.h"
#include "libc/null.h"


int strlen(char *str);
char *strcpy(char *destination, char *source);
char *strcat(char *destination, char *source);

#endif

