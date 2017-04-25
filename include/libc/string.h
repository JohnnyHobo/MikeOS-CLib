#ifndef MOSCLIB_HAS_STRFUNC
#define MOSCLIB_HAS_STRFUNC

int strlen(char *str);
char *strcpy(char *destination, char *source);
char *strcat(char *destination, char *source);
char *strncpy(char *destination, char *source, size_t num);
int strcmp(char *str1, char *str2);
char *strncat(char *destination, char *source, size_t num);

#endif

