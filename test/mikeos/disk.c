#include <mikeos.h>
#include <stdio.h>

char filename[13];
char filename2[13];
char filelist[1024];
char filedata[32*1024];
int filesize;

int main()
{
	int i, hash;

	printf("Retrieving list of files...\n");
	os_get_file_list(filelist);
	printf("Here is the file list on the disk:\n%s\n", filelist);

	printf("Now select a file to display.\n");
	os_wait_for_key();

	filesize = 0;
	if (!os_load_file(os_file_selector(), filedata, &filesize)) {
		printf("File load failed.\n");
		os_wait_for_key();
		exit(0);
	}

	os_clear_screen();

	for (i = 0; i < filesize; i++) {
		if (filedata[i] == '\n') {
			os_print_newline();
		} else {
			os_print_char(filedata[i]);
		}
	}

	printf("File size was: %d bytes\n", filesize);

	os_print_newline();
	os_wait_for_key();

	checkfile("KERNEL.BIN");
	checkfile(random_filename(filename));

	random_filename(filename);
	random_filename(filename2);

	printf("Creating file \"%s\"...", filename);
	
	if (os_create_file(filename) && os_file_exists(filename)) {
		printf("Success!\n");
	} else {
		printf("Failure.\n");
	}

	printf("Moving file from \"%s\" to \"%s\"..", filename, filename2);
	if (os_rename_file(filename, filename2) &&  !os_file_exists(filename) 
			&& os_file_exists(filename2)) {
		printf("Success!\n");
	} else {
		printf("Failure.\n");
	}

	printf("Erasing file \"%s\"...", filename2);
	if (os_remove_file(filename2) && !os_file_exists(filename2)) {
		printf("Success!\n");
	}
	else {
	 	printf("Failure.\n");
	}

	filesize = 512;

	for (i = 0; i < filesize; i++) {
		filedata[i] = os_get_random(0, 255);
	}

	hash = hash_bytes(filedata, filesize);

	printf("Writing %d bytes to the file \"%s\".\n", filesize, filename);
	if (os_write_file(filename, filedata, filesize) && 
			os_file_exists(filename) && 
			os_get_file_size(filename, &i) &&
			i == filesize) {
		printf("Success!\n");
	} else {
		printf("Failure.\n");
	}
	printf("Hash is %d\n", hash);

	printf("Verifying file contents...\n");

	if (os_load_file(filename, filedata, &filesize)  && 
			hash_bytes(filedata, filesize) == hash) {
		printf("Verification succeeded.\n");
	} else {
		printf("Verification failed.\n");
		printf("New hash is: %d\n", hash_bytes(filedata, filesize));
	}

	printf("Removing file \"%s\"\n", filename);
	os_remove_file(filename);

	os_print_string("Done...");
	os_wait_for_key();
	os_print_newline();


	return 0;
}


void checkfile(char *filename)
{
	printf("Does file \"%s\" exists? ", filename);
	if (os_file_exists(filename)) {
		os_get_file_size(filename, &filesize);
		printf("Yes, and the size is %d bytes\n", filesize);
	} else {
		printf("No.\n");
	}
}


char *random_filename(char *filename)
{
	int i;

	for (i = 0; i < 12; i++) {
		if (i == 8) {
			filename[i] = '.';
			continue;
		}
		filename[i] = os_get_random('A', 'Z');
	}
	filename[i] = '\0';

	return filename;
}


int hash_bytes(int *data, int bytes)
{
	int i;
	int hash = 0;
	int len = bytes / 4;

	for (i = 0; i < len; i++) {
		hash += data[i];
	}

	return hash;
}



