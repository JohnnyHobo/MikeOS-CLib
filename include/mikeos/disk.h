#ifndef MOSCLIB_HAS_DISK
#define MOSCLIB_HAS_DISK
void os_get_file_list(void *buffer);
int os_load_file(char *filename, void *buffer, int *size);
int os_write_file(char *filename, void *buffer, int size);
int os_file_exists(char *filename);
int os_create_file(char *filename);
int os_remove_file(char *filename);
int os_rename_file(char *oldname, char *newname);
int os_get_file_size(char *filename, int *size);
#endif
