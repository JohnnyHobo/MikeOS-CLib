#include "common/minmax.h"
#include "mikeos/string.h"
#include "textio/rawtio.h"


void charout(char ch)
{
	textio_write_char(ch);
}

void grabchar(char *ch, int *colour)
{
	textio_read_char(colour, ch);
}

void setchar(char ch, int col, int row)
{
	col = abscol(col);
	row = absrow(row);
	textio_set_char(ch, col, row);
}

void vline(char ch, int col, int row, int len)
{
	textio_draw_vline(ch, len, absrow(row), abscol(col));
}

void hline(char ch, int col, int row, int len)
{
	textio_draw_hline(ch, len, absrow(row), abscol(col));
}

void rectangle(char ch, int c1, int r1, int c2, int r2)
{
	int start_row, end_row, start_col, end_col;

	r1 = absrow(r1);
	r2 = absrow(r2);
	c1 = abscol(c1);
	c2 = abscol(c2);

	start_row = min(r1, r2);
	end_row = max(r1, r2);
	start_col = min(c1, c2);
	end_col = max(c1, c2);

	textio_draw_block(ch, start_row, start_col, end_row, end_col);
}

void grabarea(char *buffer, int c1, int r1, int c2, int r2)
{
	int start_row, end_row, start_col, end_col;

	r1 = absrow(r1);
	r2 = absrow(r2);
	c1 = abscol(c1);
	c2 = abscol(c2);

	start_row = min(c1, c2);
	end_row = max(c1, c2);
	start_col = min(c1, c2);
	end_col = max(c1, c2);

	textio_grab_area(start_row, start_col, end_row, end_col, buffer);
}


void putarea(char *buffer, int c1, int r1, int c2, int r2)
{
	int start_row, end_row, start_col, end_col;

	r1 = absrow(r1);
	r2 = absrow(r2);
	c1 = abscol(c1);
	c2 = abscol(c2);

	start_row = min(c1, c2);
	end_row = max(c1, c2);
	start_col = min(c1, c2);
	end_col = max(c1, c2);

	textio_restore_area(start_row, start_col, end_row, end_col, buffer);
}


int textcolour(int colour)
{
	if (colour == -1) {
		return textio_get_text_colour();
	}

	textio_set_text_colour(colour);
	return textio_get_text_colour();
}


int outpage(int page)
{
	if (page == -1) {
		return textio_get_output_page();
	}

	textio_set_output_page(page);
	return textio_get_output_page();
}

int viewpage(int page)
{
	if (page == -1) {
		return textio_get_visible_page();
	}

	textio_set_visible_page(page);
	return textio_get_output_page();
}


int strout(char *str)
{
	if (str) {
		textio_print_string(str);
		return os_string_length(str);
	} else {
		return -1;
	}
}


int newline()
{
	int row, col;

	textio_newline();
	textio_get_cursor(&row, &col);

	return row;
}

void movecur(int col, int row)
{
	int maxrow, maxcol;

	row = absrow(row);
	col = abscol(col);
	textio_set_cursor(row, col);
}


void getcur(int *col, int *row)
{
	textio_get_cursor(row, col);
}

void scroll(int lines)
{
	textio_scroll_down(lines);
}

void clearscr()
{
	textio_clear_screen();
}

void scrlimit(int col, int row)
{
	textio_set_screen_limits(row, col);
}

int maxcol()
{
	int row, col;

	textio_get_screen_limits(&row, &col);
	return col;
}

int maxrow()
{
	int row, col;

	textio_get_screen_limits(&row, &col);
	return row;
}

int scrollmode(int mode)
{
	if (mode == -1) {
		return textio_get_scroll_mode();
	}

	textio_set_scroll_mode(mode);
	return textio_get_scroll_mode();
}


int textmode(int mode)
{
	if (mode == -1) {
		return textio_get_text_mode();
	}

	textio_set_text_mode(mode);
	return textio_get_text_mode();
}



int absrow(int row)
{
	int maxrow, maxcol;

	textio_get_screen_limits(&maxrow, &maxcol);
	if (row < 0) row += maxrow + 1;
	return row;
}

int abscol(int col)
{
	int maxrow, maxcol;

	textio_get_screen_limits(&maxrow, &maxcol);
	if (col < 0) col += maxcol + 1;
	return col;
}


int advcur(int direction)
{
	int x, y, max_x, max_y;
	
	if (direction == 0) {
		textio_advance_cursor();
	} else if (direction == 1) {
		textio_reverse_cursor();
	} else if (direction == 2) {
		textio_get_cursor(&x, &y);
		if (y > 0) {
			textio_set_cursor(x, --y);
		}
	} else if (direction == 3) {
		textio_get_cursor(&x, &y);
		textio_get_screen_limits(&max_x, &max_y);
		if (y < max_y) {
			textio_set_cursor(x, ++y);
		} else {
			textio_scroll_down(1);
		}
	}
}

