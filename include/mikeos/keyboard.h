#ifndef MOSCLIB_HAS_MIKEOS_KEYBOARD
#define MOSCLIB_HAS_MIKEOS_KEYBOARD

/** \anchor keyboard_api
  */
 
#define ESC_KEY		0x011B
#define ENTER_KEY	0x1C0D

#define UP_KEY		0x48E0
#define DOWN_KEY	0x50E0
#define LEFT_KEY	0x4BE0
#define RIGHT_KEY	0x4DE0

#define INSERT_KEY	0x52E0
#define DELETE_KEY	0x53E0
#define HOME_KEY	0x47E0
#define END_KEY		0x4FE0
#define PAGEUP_KEY	0x49E0
#define PAGEDOWN_KEY	0x51E0


/** \brief Checks for keyboard input without waiting.
  *
  * \return The keycode pressed or zero if no key was pressed. The lower half 
  * of the return is the ASCII value of the key pressed if one exists.
  * 
  * Many constants exist in the form *_KEY for common keys.
  */
short os_check_for_key();

/** \brief Waits for keyboard input. 
  * 
  * \return The keycode pressed. The lower half of the return is the ASCII
  * value of the key pressed if one exists.
  *
  * Many constants exist in the form *_KEY for common keys.
  */
short os_wait_for_key();

#endif
