#include "mikeos/math.h"
#include "libc/number.h"
#include "common/minmax.h"

int rand()
{
	return os_get_random(0, RAND_MAX);
}



