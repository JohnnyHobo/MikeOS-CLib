#ifndef MOSCLIB_HAS_COMMON_LOADER
#define MOSCLIB_HAS_COMMON_LOADER

/** The structure passed to __start__() by the program loader code.
  * It provides information need to initialise the memory manager, 
  * call the operating system through os_* wrappers and start main().
  *
  * Addresses of loader functions are 16-bit segmented addresses.
  * Otherwise address passed are flat 32-bit addresses.
  */
struct loader {
	int argc;		/**< Number of args to be passed to main() */
	char **argv;		/**< args to be passed to main() */
	void *os_exit;		/**< Routine to return control to the OS. */
	char *segoffs;		/**< The flat offset of the OS's data. */
	void *os_stack;		/**< The stack to set before calling exitptr.*/
	void *os_call;		/**< Routine to make call the OS. */
	void *os_ds;		/**< Data segment used by the OS. */
	char *lowmem_start;	/**< Offset in os_ds to put data for the OS. */
	long lowmem_size;	/**< Maximum amount of data to sent the OS. */
	char *highmem_start;	/**< Starting address for the memory manager.*/
	long highmem_size;	/**< Bytes available for memory manager. */
};

#endif
