#ifndef MOSCLIB_HAS_MATH
#define MOSCLIB_HAS_MATH

#include "mikeos/struct.h"

/** \brief Converts an 8-bit BCD number to a binary number.
  * \param bcd The number to convert.
  * \return The converted binary number.
  */
int os_bcd_to_int(char bcd);

/** Produces the negative value of a long.
  * \param The value to negate.
  * \return The negated value.
  */
long os_long_int_negate(long value);

/** \brief Generate a random number between two values.
  * \param min The lowest value generated. Note this is a signed short.
  * \param max The highest value generated. Note this is a signed short.
  * \return A random number.
  */
int os_get_random(unsigned short min, unsigned short max);

#endif

