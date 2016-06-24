#ifndef MOSCLIB_HAS_SCREEN
#define MOSCLIB_HAS_SCREEN
void os_print_string(const char *str);
void os_clear_screen();
void os_move_cursor(int row, int col);
void os_get_cursor_pos(int *row, int *col);
void os_print_horiz_line(int type);
void os_show_cursor();
void os_hide_cursor();
void os_draw_block(int colour, int x, int y, int width, int finish_y);
char *os_file_selector();
int os_list_dialog(char *list, char *help1, char *help2);
void os_draw_background(char *top_text, char *bottom_text, int colour);
void os_print_newline();
char *os_input_dialog(char *buffer, char *msg2);
int os_dialog_box(char *msg1, char *msg2, char *msg3, int type);
void os_print_space();
void os_print_digit(int digit);
void os_print_1hex(unsigned char value);
void os_print_2hex(unsigned char value);
void os_print_4hex(unsigned short value);
void os_print_char(char value);
char *os_input_string(char *buffer, int max_bytes);
#endif

