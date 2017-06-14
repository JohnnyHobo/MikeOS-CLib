#ifndef MOSCLIB_HAS_MIKEOS_MISC
#define MOSCLIB_HAS_MIKEOS_MISC

/** \brief Retrieve the current MikeOS API version.
  * \return A numeric version number.
  */
int os_get_api_version();

/** \brief Wait for a given amount of time.
  * \param time The time to wait in tenths of a second.
  */
void os_pause(int time);

/** \brief Display an error message and halt the operating system.
  * \param error The message to display.
  */
void os_fatal_error(char *error);

#endif


