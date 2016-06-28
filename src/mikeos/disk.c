asm("%include 'mikedev.inc'");
asm("%include 'oscall/disk.asm'");

/* Set 'oscall/disk.asm' for the assembly macros used in this file. */

/** @brief Retrieves a comma seperated file list from the disk.
  * @param buffer The location in memory to put the list.
  *
  * Note that there is no size limit to the amount of data this function can
  * return. A buffer size of at least 1024 bytes is recommended, allowing for
  * 78 filenames in 8.3 format.
  *
  * The individual filename are seperated with a comma and the list is
  * terminated with a null character.
  *
  * If a disk error occurs or there are no files on the disk an empty list is 
  * returned, consisting only of a terminating null character.
  */
void os_get_file_list(char *buffer)
{
	asm("OSCALL_GET_FILE_LIST");
}

/** @brief Loads a file from the disk.
  *
  * Make sure to check the file size before loading with os_get_file_size.
  * Otherwise there might not be enough room in the buffer.
  * 
  * @param filename The name of the file to load. (8.3 format)
  * @param buffer The location in memory to load the file.
  * @param size The size of the file just loaded.
  * @return Zero if a disk error occurred, otherwise non-zero.
  */

int os_load_file(char *filename, void *buffer, int *size)
{
	asm("OSCALL_LOAD_FILE");
}

/** @brief Stores a file to the disk.
  *  
  * This function will return an error if the file already exists, can't be
  * created or another disk error occurs.  Make sure to check if the file 
  * exists with os_check_file_exists to help determine the cause of failure.
  * 
  * To overwrite an existing file, use os_remove_file to delete the old file
  * before writing.
  *
  * @param filename The name of the new file to store.
  * @param buffer The location of the file data in memory.
  * @param size The number of bytes to write.
  * @return Zero if an error occurred, otherwise non-zero.
  */
int os_write_file(char *filename, void *buffer, int size)
{
	asm ("OSCALL_WRITE_FILE");
}

/** @brief Determines whether a file exists on the disk.
  * @param filename The file to search for.
  * @return Zero if the file does not exist or a disk error occurred.
  */
int os_file_exists(char *filename)
{
	asm("OSCALL_FILE_EXISTS");
}

/** @brief Creates an empty (zero byte) file on the disk.
  * @param filename The filename to create.
  * @return Zero if a disk error occurred, otherwise non-zero.
  */
int os_create_file(char *filename)
{
	asm("OSCALL_CREATE_FILE");
}

/** @brief Removes a file from the disk.
  * @param filename The file to remove.
  * @return Zero if a disk error occurred or the file does not exist.
  */
int os_remove_file(char *filename)
{
	asm("OSCALL_REMOVE_FILE");
}

/** @brief Changes the name of an existing file.
  * 
  * This function may return an error if the file to be renamed does not exist
  * or the filename to 
  *
  * Make sure the check both filenames with os_check_file_exists to help
  * determine the cause of the problem.
  * 
  * @param oldname The name of the file to rename.
  * @param newname The new name for the file.
  * @return Zero if an error occurred, otherwise non-zero.
  */
int os_rename_file(char *oldname, char *newname)
{
	asm("OSCALL_RENAME_FILE");
}

/** @brief Finds the size of a file on the disk.
  * @param filename File to find the size of.
  * @param size Returned size of the file.
  * @return Zero if an error occurred, otherwise non-zero.
  */
int os_get_file_size(char *filename, int *size)
{
	asm("OSCALL_GET_FILE_SIZE");
}

