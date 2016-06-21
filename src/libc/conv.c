#include "mikeos/string.h"

int atoi(char *str)
{
	return os_string_to_int(str);
}

