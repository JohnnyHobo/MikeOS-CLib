#include "mikeos/string.h"
#include "libc/types.h"

int strlen(char *str)
{
	return os_string_length(str);
}

char *strcpy(char *destination, char *source)
{
	os_string_copy(source, destination);
	return destination;
}

char *strcat(char *destination, char *source)
{
	os_string_join(destination, source, destination);
	return destination;
}

char *strncpy(char *destination, char *source, size_t num)
{
	if (os_string_length(source) < num) {
		os_string_copy(destination, source);
	} else {
		memcpy(destination, source, num);
	}
	
	return destination;
}


