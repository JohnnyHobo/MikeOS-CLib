#include <common/loader.h>

#define MAX_ARGS 16
#define MAX_ARGLEN 256

void memory_init(void *baseaddr, int size);

struct loader *osdata;
void *os_call;
void *os_ds;
char *lowmem_start;
int lowmem_segoffs;


void __start__(struct loader *ldr)
{
	osdata = ldr;

	os_call = ldr->os_call;
	os_ds = ldr->os_ds;

	lowmem_start = ldr->lowmem_start - ldr->segoffs;
	lowmem_segoffs = ldr->segoffs;

	memory_init(ldr->highmem_start, ldr->highmem_size);

	main(ldr->argc, ldr->argv);
	_Exit();
}


void _Exit()
{
	int exit = osdata->os_exit;
	int stack = osdata->os_stack;
	
	/* Restore the original stack and call the os_exit routine. */
	asm(	"mov ebx, [ebp - 4]\n"

		"mov ax, [ebp - 10]\n"
		"cli\n"
		"mov sp, [ebp - 8]\n"
		"mov ss, ax\n"
		"sti\n"

		"push dword ebx\n"
		"retf");

}

int __Irq5Isr = 0xCB;

