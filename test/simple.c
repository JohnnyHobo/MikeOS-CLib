#include <mikeos.h>

int main()
{
	asm("xchg bx, bx");
	os_print_string("Hello World\r\n");
	return 0;
}
