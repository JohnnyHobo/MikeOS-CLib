#include "mikeos.h"

char filename[13];
char *text;
char

int main(int argc, char **argv)
{
	os_clear_screen();
	os_cursor_off();
	
	if (argc > 0 && os_file_exists(*argv[0])) {
		text = malloc(os_file_size(*argv[0]));
		if (!file) {
			printf("File %s too large\n", *argv[0]);
			exit(0);
		}
		
		os_string_copy(*argv[0], filename);
	}
			