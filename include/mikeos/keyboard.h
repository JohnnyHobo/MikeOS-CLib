#ifndef MOSCLIB_HAS_KEYBOARD
#define MOSCLIB_HAS_KEYBOARD
int os_check_for_key();
int os_wait_for_key();

#define ESC_KEY		0x011B
#define ENTER_KEY	0x1C0D
#define UP_KEY		0x48E0
#define DOWN_KEY	0x50E0
#define LEFT_KEY	0x4BE0
#define RIGHT_KEY	0x4DE0
#endif
