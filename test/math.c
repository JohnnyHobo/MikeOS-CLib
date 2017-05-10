#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	div_t result;
	int numerator = 23;
	int denominator = 4;
	char buffer[10];

	printf("Testing integer divisor through div().");
	printf("Dividing %d by %d\n", numerator, denominator);
	result = div(numerator, denominator);
	printf("Result is %d remainder %d\n", result.quot, result.rem);

	fgets(buffer, 8, stdin);

	return 0;
}

