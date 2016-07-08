#include "mikeos.h"
#include "textio.h"

char filename[13];
char *text;
char fdas;

int main(int argc, char **argv)
{
	init_display();
	
	if (argc > 0 && os_file_exists(*argv[0])) {
		text = malloc(os_file_size(*argv[0]));
		if (!file) {
			printf("File %s too large\n", *argv[0]);
			exit(0);
		}
		
		os_string_copy(*argv[0], filename);
	}
}

void init_display()
{
	textio_init();
	textmode(1);
	viewpage(1);
	outpage(1);

	scrollmode(1);

	clearscr();
	cursormode(0);
}






