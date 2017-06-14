#ifndef MOSCLIB_HAS_MIKEOS_STRING
#define MOSCLIB_HAS_MIKEOS_STRING

/** \brief Find the number of ASCII characters in a string.
  * \param str A pointer to the string to count.
  * \return The number of characters in the given string.
  * May be zero if the string contains only a null terminator.
  *
  * All characters a single bytes terminated by a null (0) character.
  * The null terminator is not included in the length.
  */
int os_string_length(char *str);

/** \brief Locates a given character in a string.
  * \param str The string to search.
  * \param to_find The character to search for.
  * \return If the character was found, the offset of the character in the
  * string starting from one. Otherwise, zero.
  */
int os_find_char_in_string(char *str, char to_find);

/** \brief Reverses the order of characters in a string.
  * \param str The string to reverse.
  * \return The string pointer from \a str. The string is modified.
  */
char *os_string_reverse(char *str);

/** \brief Replaces all instances of a given character in a string.
  * \param str The string the change.
  * \param to_find The character to search for.
  * \param replacement The character to change \a to_find to.
  */
char *os_string_charchange(char *str, char to_find, char replacement);

/** \brief Capitalises all letters in a string.
  * \param str The string to uppercase.
  * \return \a str is returned. The string is modified.
  *
  * Lowercase alphabetic characters are converted to their uppercase 
  * equivalent. All other characters remain unchanged.
  */
char *os_string_uppercase(char *str);

/** \brief Converts all letters in the string to lowercase.
  * \param str The string to convert.
  * \return \a str is returned. The string is modified.
  * 
  * Uppercase alphabetic characters are converted to their lowercase
  * equivelent. All other characters remain unchanged.
  */
char *os_string_lowercase(char *str);

/** \brief Copies a string to a new memory locations.
  * \param src The string to copy.
  * \param dest The memory location to copy to.
  *
  * The programmer must ensure the destination is large enough to accept the
  * string. The entire string is copied including the null character at the
  * end.
  */
char *os_string_copy(char *src, char *dest);

/** \brief Shorten a string to the given number of characters.
  * \param str The string to shorten.
  * \param length The number of characters to limit the string to.
  * \return \a src is return. The string is modified.
  */
char *os_string_truncate(char *str, int length);

/** \brief Combines two string together.
  * \param str1 The string to be put at the beginning.
  * \param str2 The string to be put at the end.
  * \param dest A buffer to store the result in. 
  * \return \a dest is returned.
  * 
  * The \a dest buffer should be at least large enough to the number of 
  * characters in both strings added together plus one character.
  * No spaces or extra characters are inserted between the two strings.
  */
char *os_string_join(char *str1, char *str2, char *dest);

/** \brief Removes spaces from the start and end of a string.
  * \param str The string to change.
  * \return \a str is returned. The string is modified.
  */
char *os_string_chomp(char *str);

/** \brief Removes a given character from a string.
  * \param str The string to modify.
  * \param to_remove The character to remove.
  * \return \a str is returned. The string is modified.
  */
char *os_string_strip(char *str, char to_remove);

/** \brief Check if two string match.
  * \param str1 The first string to compare.
  * \param str2 The second string to compare.
  * \return Non-zero if matching, otherwise zero.
  */
int os_string_compare(const char *str1, const char *str2);

/** \brief Check if two string match up to a given number of characters.
  * \param str1 The first string to compare.
  * \param str2 The second string to compare.
  * \param num_chars Number of characters to compare up to.
  * \return Non-zero if matching, otherwise zero.
  */
int os_string_strincmp(const char *str1, const char *str2, int num_chars);

/** \brief Splits a string by spaces.
  * \param src The string to split. This string is modified.
  * \param str1 The address of the first result string.
  * \param str2 The address of the second result string.
  * \param str3 The address of the third result string.
  * \param str4 The address of the forth result string.
  *
  * The result strings may be null if they were not found.
  */
void os_string_parse(char *src, char **str1, char **str2, char **str3, char **str4);

/** \brief Converts an ASCII string with an unsigned number in numeric type.
  * \param str The string to convert.
  * \return An equivelent numeric value.
  *
  * This function only works for values that fit in an unsigned short.
  */
unsigned short os_string_to_int(char *str);

/** \brief Converts an unsigned number into an ASCII string.
  * \param value The number to convert.
  * \return A pointer to an internal buffer with the equivelent string.
  *
  * For a much more flexible version that supports larger numbers see
  * \ref os_long_int_to_string.
  */
const char *os_int_to_string(unsigned short value);

/** \brief Converts a signed number into an ASCII string.
  * \param value The number to convert.
  * \return A pointer to an internal buffer with the equivelent string.
  */
const char *os_sint_to_string(signed short value);

/** \brief Converts a long unsigned number into an ASCII string.
  * \param longint The number to convert.
  * \param base The number system in use (e.g. 10 for decimal).
  * \param buffer The location to put the result in.
  * \return \a buffer is returned containing the result.
  */
char *os_long_int_to_string(long longint, int base, char *buffer);

/** Time formats to pass \a os_set_time_fmt()*/
enum time_format {
	CLOCK_12H,	/**< 12 hour format, e.g. 11:31 */
	CLOCK_24H 	/**< 24 hour format, e.g. 2331 hours */
};

/**
  * \brief Sets the format the time will be returned in.
  * \param format Format to set. For available formats, see \ref time_format.
  *
  * To get the current time as a string, see \ref os_get_time_string.
  */
void os_set_time_fmt(int format);

/** \brief Get the current time as a string.
  * \param buffer The location to store the output in.
  * Should be able to store the longest time from any format.
  * \return \a buffer is returned with the output stored in it.
  * 
  * To set the format the time is given in, see \ref os_set_time_fmt().
  */
char *os_get_time_string(char *buffer);

/** Date formats to pass \a os_set_date_fmt()*/
enum DATE_FORMAT {
	MDY_DATE_FORMAT,	/**< American Style MM/DD/YYYY */
	DMY_DATE_FORMAT,	/**< British Style: DD/MM/YYYY */
	YMD_DATE_FORMAT,	/**< ISO8601 Style: YYYY/MM/DD */
};
	

/** Use the name of the month rather than the number.
  * Can be passed to \ref os_set_date_fmt().
  * Must be OR'd with an existing date format.
  */
#define ALPHABETIC_MONTH 0x80

/** Date with a named month to avoid confusion. */
#define SIMPLE_DATE	(DMY_DATE_FORMAT | ALPHABETIC_MONTH)
/** Use MM/DD/YYYY format. */
#define AMERICAN_DATE	(MDY_DATE_FORMAT | ('/' << 8))
/** Use DD/MM/YYYY format. */
#define BRITISH_DATE	(DMY_DATE_FORMAT | ('/' << 8))
/** Use YYYY-MM-DD format. */
#define ISO8601_DATE	(YMD_DATE_FORMAT | ('-' << 8))

/** \brief Changes the format dates are returned in.
  * \param format to set. For available formats, see \ref DATE_FORMAT.
  *
  * To get the current date as a string, see \ref os_get_date_string.
  */
void os_set_date_fmt(int format);

/** \brief Retrieves the current date as a string.
  * \param buffer The location to store the output in.
  * Must be large enough to hold the largest date in any format.
  * \return \a buffer is return with the output stored in it.
  * 
  * To set the format the date is displayed in, see \ref os_set_date_fmt().
  */
char *os_get_date_string(char *buffer);

#endif
