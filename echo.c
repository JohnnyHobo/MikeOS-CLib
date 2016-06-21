#include "mikeos.h"
#include "stdio.h"

int main()
{
	int key;
	
	printf("Press any key to see it on the screen.\n");
	printf("Press ESC to exit.\n");
	
	do {
		key = os_wait_for_key();
		
		printf("Key value: 0x%x, ASCII code: '%c'\n", key, (int)key);
	} while (key != ESC_KEY);
	
	return 0;
}
		