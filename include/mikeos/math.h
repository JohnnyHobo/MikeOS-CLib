#ifndef MOSCLIB_HAS_MATH
#define MOSCLIB_HAS_MATH

#include "mikeos/struct.h"

int os_bcd_to_int(char bcd);
void os_long_int_negate(long value);
int os_get_random(unsigned short min, unsigned short max);
#endif

