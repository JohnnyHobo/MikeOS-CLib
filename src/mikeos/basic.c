asm("%include 'mikedev.inc'");
asm("%include 'oscall/basic.asm'");

void os_run_basic(void *code, int size)
{
	asm("OSCALL_RUN_BASIC");
}

