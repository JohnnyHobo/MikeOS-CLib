#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char **arg;

	if (argv[0] != 0) {
		printf("Program name is %s\n", argv[0]);
	} else {
		printf("Program name unknown\n");
	}

	printf("Number of arguments is: %d\n", argc - 1);

	puts("Arguments: ");

	for (arg = &argv[1]; *arg != 0; arg++) {
		printf("\"%s\"\n", *arg);
	}

	exit(1);
}



