#include "memory/memory.h"
#include "libc/memory.h"
#include "libc/types.h"

void *calloc(size_t num, size_t size)
{
	void *mem;

	mem = malloc(num * size);
	if (!mem) return NULL;

	return memset(mem, 0, num * size);
}

