#include "memory/memory.h"
#include "libc/memory.h"
#include "libc/types.h"

void *calloc(size_t num, size_t size)
{
	void *mem;
	size_t total;

	total = size * num;
	/* Check for an overflow */
	if (num == 0 || total / num != size) return NULL;

	mem = malloc(total);
	if (!mem) return NULL;

	return memset(mem, 0, total);
}

