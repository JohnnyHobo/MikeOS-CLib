#include <stdio.h>
#include <string.h>
#include <mikeos.h>

char *str1 = "Hello ";
char *str2 = "World.";
char output[20];

int main()
{
	int len;

	strcpy(output, str1);
	strcat(output, str2);
	printf("%s\n", output);

	output[0] = '\0';
	strncat(output, str1, 30);
	strncat(output, str2, 4);
	printf("%s\n", output);

	sprintf(output, "Hello %s\n", str2);
	printf(output);
	snprintf(output, 20, "%d %d %d %d %d\n", 1, 21, 3, 0, -2);
	printf(output);
	snprintf(output, 20, "Overflow: %s", "1234567890");
	printf("%s\n", output);
	
	os_wait_for_key();

	return 0;
}


