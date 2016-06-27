asm("%include 'mikedev.inc'");
asm("%include 'oscall/disk.asm'");

void os_get_file_list(char *buffer)
{
	asm("OSCALL_GET_FILE_LIST");
}

int os_load_file(char *filename, void *buffer, int *size)
{
	asm("OSCALL_LOAD_FILE");
}

int os_write_file(char *filename, void *buffer, int size)
{
	asm ("OSCALL_WRITE_FILE");
}

int os_file_exists(char *filename)
{
	asm("OSCALL_FILE_EXISTS");
}

int os_create_file(char *filename)
{
	asm("OSCALL_CREATE_FILE");
}

int os_remove_file(char *filename)
{
	asm("OSCALL_REMOVE_FILE");
}

int os_rename_file(char *oldname, char *newname)
{
	asm("OSCALL_RENAME_FILE");
}

int os_get_file_size(char *filename, int *size)
{
	asm("OSCALL_GET_FILE_SIZE");
}

