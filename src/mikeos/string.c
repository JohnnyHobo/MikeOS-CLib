#include "mikeos/struct.h"

asm("%include 'mikedev.inc'");
asm("%include 'oscall/string.asm'");

int os_string_length(char *str)
{
	asm("OSCALL_STRING_LENGTH");
}

int os_find_char_in_string(char *str, char to_find)
{
	asm("OSCALL_FIND_CHAR_IN_STRING");
}

char *os_string_reverse(char *str)
{
	asm("OSCALL_STRING_REVERSE");
}

char *os_string_charchange(char *str, char to_find, char replace_with)
{
	asm("OSCALL_STRING_CHARCHANGE");
}

char *os_string_uppercase(char *str)
{
	asm("OSCALL_STRING_UPPERCASE");
}

char *os_string_lowercase(char *str)
{
	asm("OSCALL_STRING_LOWERCASE");
}

void os_string_copy(char *src, char *dest)
{
	asm("OSCALL_STRING_COPY");
}

char *os_string_truncate(char *str, int length)
{
	asm("OSCALL_STRING_TRUNCATE");
}

char *os_string_join(char *str1, char *str2, char *dest)
{
	asm("OSCALL_STRING_JOIN");
}

char *os_string_chomp(char *str)
{
	asm("OSCALL_STRING_CHOMP");
}

char *os_string_strip(char *str, char to_remove)
{
	asm("OSCALL_STRING_STRIP");
}

int os_string_compare(char *str1, char *str2)
{
	asm("OSCALL_STRING_COMPARE");
}

int os_string_strincmp(char *str1, char *str2, int num_chars)
{
	asm("OSCALL_STRING_STRINCMP");
}

void os_string_parse(char *src, char **str1, char **str2, char **str3, char **str4)
{
	asm("OSCALL_STRING_PARSE");
}

int os_string_to_int(char *str)
{
	asm("OSCALL_STRING_TO_INT");
} 

char *os_int_to_string(unsigned int value)
{
	asm("OSCALL_INT_TO_STRING");
}

char *os_sint_to_string(signed int value)
{
	asm("OSCALL_SINT_TO_STRING");
}

char *os_long_int_to_string(struct longint *value, int base, char *buffer)
{
	asm("OSCALL_LONG_INT_TO_STRING");
}

void os_set_time_fmt(int flags)
{
	asm("OSCALL_SET_TIME_FMT");
}

char *os_get_time_string(char *buffer)
{
	asm("OSCALL_GET_TIME_STRING");
}

void os_set_date_format(int flags)
{
	asm("OSCALL_SET_DATE_FMT");
}

char *os_get_date_string(char *buffer)
{
	asm("OSCALL_GET_DATE_STRING");
}


