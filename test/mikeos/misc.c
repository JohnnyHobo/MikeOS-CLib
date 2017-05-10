#include <mikeos.h>
#include <stdio.h>

int main()
{
	printf("The current API version is: %d\n", os_get_api_version());

	printf("Pausing execution for 3 seconds...\n");
	os_pause(30);
	printf("Done.\n");

	printf("Press any key to generate a fatal error!\n");
	os_wait_for_key();

	os_fatal_error("You pressed a key!");
	
	printf("Whaaaaaa?\n");
	
	return 0;
}

