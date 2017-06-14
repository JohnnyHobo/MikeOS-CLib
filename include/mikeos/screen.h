#ifndef MOSCLIB_HAS_MIKEOS_SCREEN
#define MOSCLIB_HAS_MIKEOS_SCREEN

/** \anchor screen_api
  */

/** @brief Prints a string on the screen.
  * @param str The string to display.
  *
  * The string is printed at the current cursor position and changes the
  * character but not the colour of any other character is moves over.
  * After printing the cursor position will be the position at the end of the
  * string on the screen. 
  *
  * The string is terminated by a null character and may span any number of
  * lines by adding a DOS newline sequence "\r\n".
  */
void os_print_string(const char *str);

/** @brief Erases the screen contents.
  *
  * All characters and colours on the screen are reset to their default values.
  */
void os_clear_screen();

/** @brief Changes the position of the cursor on the screen.
  * 
  * \param row The vertical character under the cursor.
  * \param col The horizontal character under the cursor.
  *
  * The cursor position starts at zero from the top left corner of the screen.
  * \a row and \a col are both internally converted to an unsigned char.
  */
void os_move_cursor(int row, int col);

/** \brief Retrieves the current cursor position on the screen.
  *
  * \param row Variable to store the vertical position.
  * \param col Variable to store the horizontal position.
  *
  * The cursor position starts at zero from the top left corner of the screen.
  * \a row and \a col are both prompted from an unsigned char.
  */
void os_get_cursor_pos(int *row, int *col);

enum LINE_STYLE {
	SINGLE_LINE,
	DOUBLE_LINE
};

/** \brief Draws a horizontal line across the screen.
  *
  * \param type Line style, either SINGLE_LINE or DOUBLE_LINE.
  *
  * The line begins at the first horizontal position of the cursor line and
  * finishes at the last. This is true even is the cursor is not on the first
  * horizontal position of the line. After drawing the line the cursor will be
  * moved to the first horizontal position of the next line.
  */
void os_print_horiz_line(enum LINE_STYLE type);

/** \brief Shows a visible cursor at the cursor position.
  * 
  */
void os_show_cursor();

/** \brief Hides the visible cursor.
  */
void os_hide_cursor();

/** \brief Draws a rectagular block of colour.
  *
  * \param colour The colour to draw with. 
  * For possible colours see the list of \ref bgcolours "Background Colours".
  * \param x The horizontal position to start at.
  * \param y The vertical position to start at.
  * \param width The horizontal width of the block.
  * \param finish_y The vertical position to stop at. This finishing line is 
  * not drawn on.
  *
  * Here is an example that generates a green 5 character wide and 4 character
  * tall block at the cursor row 3 and column 9.
  * \code
  * os_draw_block(GREEN_BG, 9, 3, 5, 13);
  * \endcode
  */
void os_draw_block(int colour, int x, int y, int width, int finish_y);

/** \brief Presents a file selection dialog.
  * \return A buffer containing the selected filename.
  */
char *os_file_selector();

/** \brief Presents a list dialog allowing an option to be selected.
  * \param list A comma seperate list of options.
  * \param help1 The first line of information above the list.
  * \param help2 The second line of information about the list.
  * \return If a selection was made, the item number beginning from 1.
  * If escape was pressed, 0 is returned.
  * 
  * Help string should be limited to no more than 34 characters.
  * The lists maybe any number of items but may be tedious to scroll if too
  * many are given.
  */
int os_list_dialog(char *list, char *help1, char *help2);

void os_draw_background(char *top_text, char *bottom_text, int colour);
void os_print_newline();

/** The result from a dialog with multiple buttons. */
enum DIALOG_RESPONSE {
	OKAY_RESPONSE,		/**< The user selected 'OK' */
	CANCEL_RESPONSE		/**< The user selected 'CANCEL' */
};

/** Dialog box types. */
enum DIALOG_TYPE {
	OKAY_DIALOG,		/**< Dialog box with only an okay button. */
	OKAY_CANCEL_DIALOG	/**< Dialog box with okay and cancel buttons.*/
};

/** \brief Prompts for text input with a dialog box.
  * \param buffer The buffer to store the input in.
  * \param msg The prompt to present above the message.
  */
char *os_input_dialog(char *buffer, char *msg);

/** \brief Presents a dialog box.
  * \param msg1 The first line of text.
  * \param msg2 The second line of text.
  * \param msg3 The third line of text.
  * \param type The dialog box type. See \ref DIALOG_TYPE
  */
enum DIALOG_RESPONSE os_dialog_box(char *msg1, char *msg2, char *msg3, 
		enum DIALOG_TYPE type);

/** \brief Prints a space character.
  */
void os_print_space();

/** \brief Print the character and hexadecimal representation of a string.
  * \param str A string to look at.
  */
void os_dump_string(char *str);

/** \brief Print an alphanumeric digit to the screen.
  * \param digit The value to print.
  * 
  * Values in the range of 0-9 will generate the digits '0'-'9'.
  * Values in the range of 10-36 will generate the letters 'A'-'Z'.
  */
void os_print_digit(int digit);

/** \brief Print a 4-bit value as a hexadecimal (one 'hex' character).
  * \param value The value to print.
  *
  * The upper half of `value` is discarded. The value is then converted to 
  * a hexadecimal string with "0x" appended to the start and printed to the 
  * screen.
  */
void os_print_1hex(unsigned char value);

/** \brief Print a 8-bit value as a hexadecimal (two 'hex' characters).
  * \param value The value to print.
  *
  * The value is converted to a hexadecimal string with "0x" appended to the
  * start and printed to the screen.
  */
void os_print_2hex(unsigned char value);

/** \brief Print a 16-bit value as a hexadecimal (four 'hex' characters).
  * \param value The value to print.
  *
  * The value is converted to a hexadecimal string with "0x" appended to the
  * start and then printed to the screen.
  */
void os_print_4hex(unsigned short value);

/** \brief Prints a single character to the screen.
  * \param value A character to print.
  *
  * This function is not part of the MikeOS API but needed to display a single
  * character in C.
  * Characters are printed in the same way as \ref os_print_string(), meaning a
  * DOS style newline is used.
  */
void os_print_char(char value);

/** \brief Retrieves a string of text input.
  * \param buffer The location to store the input.
  * \param max_bytes The number of bytes available in the input buffer.
  * \return \a buffer is returned with the input stored.
  * 
  * Not all versions of MikeOS versions and derivatives support limiting the 
  * input to a fixed number of characters. 
  * For these versions the buffer size should be 256 bytes.
  */
char *os_input_string(char *buffer, int max_bytes);
#endif

