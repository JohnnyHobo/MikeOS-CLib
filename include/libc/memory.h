#ifndef MOSCLIB_HAS_MEMORY
#define MOSCLIB_HAS_MEMORY

#include "include/libc/types.h"

void *memset(void *ptr, int value, size_t num);
void *memcpy(void *destination, void *source, size_t num);
void *memcmp(void *ptr1, void *ptr2, size_t num);
void *memchr(void *ptr1, void *ptr2, size_t num);

#endif

