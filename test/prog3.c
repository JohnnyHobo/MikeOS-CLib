#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	div_t r;
	int a = 32000;
	int b = 345;
	int i;
	char *ptr, *ptr2;
	char buf[10];

	r = div(a, b);

	printf("%d / %d = %d remainder %d\n", a, b, r.quot, r.rem);
	printf("Invalid allocations: %p, %p, %p %p\n", calloc(256, 256),
			calloc(40000U, 51233U), calloc(2, 50000U), 
			calloc(0, 200));
	ptr = calloc(9, 2);
	ptr2 = calloc(4, 5);
	printf("Valid allocations: %p, %p, %p\n", ptr, ptr2, calloc(10, 20));

	memset(ptr, 14, 18);
	memset(ptr2, 14, 18);
	printf("MEMCMP Equal: %d\n", memcmp(ptr, ptr2, 18));
	ptr2[17] = 12;
	printf("MEMCMP Greater: %d\n", memcmp(ptr, ptr2, 18));
	ptr2[17] = 20;
	printf("MEMCMP Lesser: %d\n", memcmp(ptr, ptr2, 18));

	ptr[6] = 'A';

	free(ptr2);
	ptr2 = memchr(ptr, 'A', 18);
	printf("MEMCHR Find Valid, Pointer: %p; Data: %d\n", ptr2, *ptr2);
	ptr2 = memchr(ptr, 'Z', 18);
	printf("MEMCHR Find Invalid, Pointer: %p\n", ptr2);

	strcpy(ptr, "One Two");
	printf("MEMMOVE initial string: %s\n", ptr);
	memmove(ptr + 4, ptr, 8);
	printf("MEMMOVE final string: %s\n", ptr);

	printf("Press ENTER to continue.\n");
	fgets(buf, 8, stdin);

	return 0;
}

