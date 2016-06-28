#ifndef MOSCLIB_HAS_STRING
#define MOSCLIB_HAS_STRING

#include "mikeos/struct.h"

int os_string_length(char *str);
int os_find_char_in_string(char *str, char to_find);
char *os_string_reverse(char *str);
char *os_string_charchange(char *str, char to_find, char replace_with);
char *os_string_uppercase(char *str);
char *os_string_lowercase(char *str);
char *os_string_copy(char *src, char *dest);
char *os_string_truncate(char *str, int length);
char *os_string_join(char *str1, char *str2, char *dest);
char *os_string_chomp(char *str);
char *os_string_strip(char *str, char to_remove);
int os_string_compare(char *str1, char *str2);
int os_string_strincmp(char *str1, char *str2, int num_chars);
void os_string_parse(char *src, char **str1, char **str2, char **str3, char **str4);
int os_string_to_int(char *str);
char *os_int_to_string(unsigned int value);
char *os_sint_to_string(signed int value);
char *os_long_int_to_string(struct longint *value, int base, char *buffer);
void os_set_time_fmt(int flags);
char *os_get_time_string(char *buffer);
void os_set_date_format(int flags);
char *os_get_date_string(char *buffer);
#endif
