#include <stdio.h>
#include <stdlib.h>

char buffer[10];

int main(int argc, char *argv[])
{
	char *stackstr = "Hello World!";
	char *heapstr;
	void *mem;
	int elem = 1024;
	int size = 50;

	printf("Stack address: %p\n", stackstr);
	printf("Allocating %d bytes to copy the string \"%s\" with malloc()\n",
			strlen(stackstr) + 1, stackstr);

	heapstr = malloc(strlen(stackstr) + 1);
	
	if (heapstr) {
		strcpy(heapstr, stackstr);
		printf("Got address: %p, copies string is: \"%s\"\n", 
				heapstr, heapstr);
	} else {
		printf("Memory allocation failed!\n");
	}

	printf("Press ENTER to continue.\n");
	fgets(buffer, 8, stdin);

	printf("Allocating %d elements with each %d bytes with calloc()\n",
			elem, size);

	mem = calloc(elem, size);

	if (mem) {
		printf("Got address: %p\n", heapstr);
	} else {
		printf("Memory allocation failed!\n");
	}

	printf("Press ENTER to continue.\n");
	fgets(buffer, 8, stdin);

	return 0;
}

