#include "mikeos/struct.h"

asm("%include 'mikedev.inc'");
asm("%include 'oscall/math.asm'");

int os_bcd_to_int(char bcd)
{
	asm("OSCALL_BCD_TO_INT");
}

void os_long_int_negate(struct longint *value)
{
	asm("OSCALL_LONG_INT_NEGATE");
}

int os_get_random(int min, int max)
{
	asm("OSCALL_GET_RANDOM");
}

