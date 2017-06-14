#ifndef MOSCLIB_HAS_MIKEOS_BASIC
#define MOSCLIB_HAS_MIKEOS_BASIC
/** \brief Runs a MikeOS BASIC program from memory.
  * \param code A pointer to the loaded code.
  * \param size The length of the code in bytes.
  * \param parameters A string with a space seperated list of parameters to 
  * give to the program.
  *
  * Refer to the "The MikeOS BASIC App Developer Handbook" included in the 
  * MikeOS documentation.
  */
void os_run_basic(void *code, int size, char *parameters);
#endif
