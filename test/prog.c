#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char first_name[50];
char last_name[50];
char full_name[100];
char *twelve = "12";

int main(int argc, char **argv)
{
	printf("What is your first name?\n");
	gets(first_name);
	printf("Hello %s\n", first_name);
	printf("Your name is %d characters long!\n", strlen(first_name));
	
	printf("What is your last name?\n");
	gets(last_name);
	strcpy(full_name, first_name);
	strcat(full_name, " ");
	strcat(full_name, last_name);
	printf("Hello again, %s\n", full_name);
	
	printf("Here's 12: %d\n", atoi(twelve));
	printf("Here's a random number: %d\n", rand());
	gets(first_name);
	
	return 0;
}

