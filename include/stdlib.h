#ifndef MOSCLIB_HAS_STDLIB
#define MOSCLIB_HAS_STDLIB
#include "memory.h"
void exit(int status);
int rand();
int atoi(char *str);

#define EXIT_SUCCESS	1
#define EXIT_FAILURE	0

#define RAND_MAX	(32768u)

#endif
