#ifndef MOSCLIB_HAS_TEXTIO_WRAP
#define MOSCLIB_HAS_TEXTIO_WRAP

void charout(char ch);
void grabchar(char *ch, int *colour);
void setchar(char ch, int col, int row);
void vline(char ch, int col, int row, int len);
void hline(char ch, int col, int row, int len);
void rectangle(char ch, int c1, int r1, int c2, int r2);
void grabarea(char *buffer, int c1, int r1, int c2, int r2);
void putarea(char *buffer, int c1, int r1, int c2, int r2);
int textcolour(int colour);
int outpage(int page);
int viewpage(int page);
int strout(char *str);
int newline();
void movecur(int col, int row);
void getcur(int *col, int *row);
void scroll(int lines);
void clearscr();
void scrlimit(int col, int row);
int maxcol();
int maxrow();
int scrollmode(int mode);
int textmode(int mode);
int absrow(int row);
int abscol(int col);
int advcur(int direction);

#endif

