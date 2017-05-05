#include <mikeos.h>
#include <stdio.h>

int main()
{
	int bcd = 0x49;
	long lneg = -123456789;

	printf("Converting BCD value: 0x%x to decimal: %d\n", bcd,
			os_bcd_to_int(bcd));

	printf("Getting a random byte: 0x%x, and another: 0x%x\n",
			os_get_random(0, 255), os_get_random(0, 255));

	printf("Getting a random short: %d, now a long: %d\n",
			os_get_random(-32000, 32767),
			(os_get_random(-32768, 32767) << 16) | 
			os_get_random(-32768, 32767));

	printf("Negating: %d into: %d\n", lneg, os_long_int_negate(lneg));

	os_wait_for_key();
	return 0;
}


