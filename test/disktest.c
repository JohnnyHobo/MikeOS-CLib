#include "mikeos.h"
#include "stdio.h"

int main()
{
	print_file_list();
	cat_file();
}

void print_file_list()
{
	char *list, *next;
	
	list = malloc(1024);

	if (!list) {
		printf("Memory Error\r\n");
		exit(0);
	}

	os_get_file_list(list);

	while (*list != 0) {
		if (*list == ',') {
			os_print_newline();
		} else {
			os_print_char(*list);
		}
		list++;
	}
	os_print_newline();
	os_wait_for_key();
}

void cat_file()
{
	char filename[13];
	char *tmp, *buffer;
	int size, i;

	tmp = os_file_selector();

	os_clear_screen();

	if (!tmp) {
		os_print_string("No file selected\r\n");
		os_wait_for_key();
		return;
	}

	os_string_copy(tmp, filename);

	buffer = malloc(20000);

	if (!buffer) {
		os_print_string("Memory Error!\r\n");
	}

	if (!os_get_file_size(filename, &size) || size > 19968) {
		printf("File size too large\n");
		os_wait_for_key();
		return;
	}

	printf("Loading file: %s\n", filename);

	if (!os_load_file(filename, buffer, &size)) {
		printf("Disk Error!\n");
		os_wait_for_key();
		return;
	}

	for (i = 0; i < size; i++) {
		if (buffer[i] == '\n') {
			os_print_newline();
		} else {
			os_print_char(buffer[i]);
		}
	}

	os_wait_for_key();
	os_print_newline();
}

	
	
