#ifndef MOSCLIB_HAS_MIKEOS_DISK
#define MOSCLIB_HAS_MIKEOS_DISK

/** \brief Retrieves a list of files in the current directory.
  * \param buffer The buffer to store the list of files in.
  * \return \a buffer is returned with the list stored.
  * 
  * The list is null terminated string with individual files seperated with a
  * comma. If a disk error occurs the list will contain no files (a zero length
  * string).
  *
  * A buffer size of 1024 is recommended.
  */
char *os_get_file_list(void *buffer);

/** \brief Load all data in a file from the disk.
  * \param filename The name of the file to load.
  * \param buffer The location to store the loaded data.
  * \param size Size of the file as determined after loading.
  * \return Non-zero if the file loaded successfully, otherwise zero.
  *
  * Note that the size may not include slack space also loaded. Round the
  * size up to the nearest 512 byte block.
  *
  * Before loading a file, you may want to determine how large it is going to
  * be with \ref os_get_file_size(), as to avoid buffer overflows.
  */
int os_load_file(char *filename, void *buffer, int *size);


/** \brief Stores data in a file.
  * \param filename The name of the file to write.
  * \param buffer The data to write.
  * \param size The number of bytes to writes.
  * \return Non-zero if the file was written successfully, otherwise zero.
  *
  * The filename must be up to eight characters followed by a period and an
  * additional three characters for the extension. The filename will be
  * converted to uppercase before saving.
  * 
  * The file must have a name that does not already exist.
  *
  * The maximum file size is currently limited to 31 KiB.
  */
int os_write_file(char *filename, void *buffer, int size);

/** \brief Determines if a give file exist in the current directory.
  * \param filename The file to check for.
  * \return Non-zero if the file was found, zero otherwise.
  */
int os_file_exists(char *filename);

/** \brief Create an empty file.
  * \param filename The name of the file to create.
  * \return Non-zero if the file was created successfully, otherwise zero.
  */
int os_create_file(char *filename);

/** \brief Deletes an existing file.
  * \param filename The file to delete.
  * \return Non-zero if the file was successfully deleted, otherwise zero.
  */
int os_remove_file(char *filename);

/** \brief Change the name of an existing file.
  * \param oldname The current name of the file to rename.
  * \param newname The new name for the file.
  */
int os_rename_file(char *oldname, char *newname);

/** \brief Retrieves the size of a file.
  * \param filename The name of the file to check.
  * \param size Where to put the size once retrieved.
  * \return Non-zero if the file size was retrieved, otherwise zero.
  *
  * \a size should not be trusted unless the function give a non-zero return
  * value. The file size may need to be rounded up to the next 512-byte block
  * to account for slack space loaded with the file.
  */
int os_get_file_size(char *filename, int *size);
#endif
