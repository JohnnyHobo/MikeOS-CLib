#ifndef MOSCLIB_HAS_TEXTIO
#define MOSCLIB_HAS_TEXTIO

void textio_init();
void textio_write_char(char ch);
void textio_read_char(int *colour, char *ch);
void textio_set_char(char ch, int y, int x);
void textio_draw_hline(char ch, int length, int start_y, int start_x);
void textio_draw_vline(char ch, int length, int start_y, int start_x);
void textio_draw_block(char ch, int start_y, int start_x, int finish_x, int finish_y);
void textio_grab_area(int start_y, int start_x, int finish_y, int finish_x, char *buffer);
void textio_restore_area(int start_y, int start_x, int finish_y, int finish_x, char *buffer);
void textio_set_text_colour(int colour);
void textio_set_output_page(int page);
void textio_set_visible_page(int page);
void textio_print_string(char *str);
void textio_reverse_cursor();
void textio_advance_cursor();
void textio_newline();
void textio_set_cursor(int row, int column);
void textio_get_cursor(int *row, int *column);
void textio_scroll_down(int lines);
void textio_clear_screen();
void textio_set_screen_limits(int row, int column);
void textio_clone_page(int src_page, int dest_page);

#endif
