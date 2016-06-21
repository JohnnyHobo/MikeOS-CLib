#include "mikeos/math.h"
#include "stdlib.h"

int rand()
{
	return os_get_random(0, RAND_MAX);
}
