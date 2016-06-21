#ifndef MOSCLIB_HAS_DISK
#define MOSCLIB_HAS_DISK
int os_get_file_list(char *store);
int os_load_file(char *filename, void *data, int *size);
int os_write_file(char *filename, int size, void *data);
int os_file_exists(char *filename);
int os_create_file(char *filename);
int os_remove_file(char *filename);
int os_rename_file(char *oldname, char *newname);
int os_get_file_size(char *filename, int *size);
int remove(char *filename);
int rename(char *oldname, char *newname);
#endif
