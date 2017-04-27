#include "mikeos/string.h"
#include "libc/nsconv.h"
#include <stdbool.h>

int atoi(char *str)
{
	return os_string_to_int(str);
}


char *uint_to_str(unsigned int value, char *str)
{

	int count;

	do {
		str[count++] = value % 10 + '0';		
		value /= 10;
	} while (value > 0);
	str[count] = '\0';

	os_string_reverse(str);
	return str;
}


char *sint_to_str(int value, char *str)
{
	int count = 0;
	int sign = false;

	if (value < 0) {
		sign = true;
		value = -value;
		count++;
	}

	do {
		str[count++] = value % 10 + '0';		
		value /= 10;
	} while (value > 0);
	str[count] = '\0';

	if (!sign) {
		os_string_reverse(str);
	} else {
		os_string_reverse(str + 1);
		str[0] = '-';
	}

	return str;
}


char *hd_to_str(int value, char *str)
{
	int count;
	char *hexchar = "0123456789ABCDEF";

	do {
		str[count++] = hexchar[value % 16];		
		value /= 16;
	} while (value > 0);
	str[count] = '\0';

	os_string_reverse(str);
	return str;
}


int str_to_sint(char *str, int *value)
{
}


