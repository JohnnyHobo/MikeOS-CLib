#ifndef MOSCLIB_HAS_MATH
#define MOSCLIB_HAS_MATH
int os_bcd_to_int(char bcd);
void os_long_int_negate(int *input, int *output);
int os_get_random(unsigned int min, unsigned int max);
#endif

