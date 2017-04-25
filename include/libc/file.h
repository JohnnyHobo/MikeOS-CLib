#ifndef MOSCLIB_HAS_FILE
#define MOSCLIB_HAS_FILE

typedef struct __file_s {
	int (*read)();
	int (*write)(char);
} FILE;

extern FILE console;
extern FILE *stdout;
extern FILE *stdin;
extern FILE *stderr;

#define EOF -1

#endif
