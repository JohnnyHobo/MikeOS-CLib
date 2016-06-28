#include "mikeos/math.h"
#include "libc/number.h"

int rand()
{
	return os_get_random(0, RAND_MAX);
}

int abs(int n)
{
	if (n > 0) return n;
	return -n;
}


