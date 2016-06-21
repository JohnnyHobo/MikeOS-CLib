#include "mikeos/string.h"

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


