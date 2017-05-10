#include "mikeos/string.h"
#include "libc/nsconv.h"
#include <stdbool.h>

int atoi(char *str)
{
	return os_string_to_int(str);
}



