#include <stdio.h>
#include <string.h>

char *str1 = "Hello";
char *str2 = "Hello";
char *str3 = "Hella";
char *str4 = "asdf";
char *str5 = "HelloWorld";
char *str6 = "Heyyyy";

int main()
{
	printf("Comparing %s and %s, result is %d\n", str1, str2, strcmp(str1, str2));
	printf("Comparing %s and %s, result is %d\n", str1, str3, strcmp(str1, str3));
	printf("Comparing %s and %s, result is %d\n", str1, str4, strcmp(str1, str4));
	printf("Comparing %s and %s, result is %d\n", str1, str5, strcmp(str1, str5));
	printf("Comparing %s and %s, result is %d\n", str1, str6, strcmp(str1, str6));
	return 0;
}


