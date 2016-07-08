#ifndef MOSCLIB_HAS_MEMORY
#define MOSCLIB_HAS_MEMORY

#include "libc/types.h"
#include "libc/null.h"
#include "memory/memory.h"

void *memset(void *ptr, int value, size_t num);
void *memcpy(void *destination, void *source, size_t num);
void *memcmp(void *ptr1, void *ptr2, size_t num);
void *memchr(void *ptr1, void *ptr2, size_t num);
void *memmove(void *destination, void *source, size_t num);
void *calloc(size_t num, size_t size);

#endif

