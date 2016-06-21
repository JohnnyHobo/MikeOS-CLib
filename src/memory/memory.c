asm("%include 'asm/memory.asm'");

int init_memory(int start, int size)
{
	asm("LIBCALL_MEMORY_INITIALISE");
}

void *malloc(int req_size)
{
	asm("LIBCALL_MEMORY_ALLOCATE");
}

void free(void *memory)
{
	asm("LIBCALL_MEMORY_FREE");
}


