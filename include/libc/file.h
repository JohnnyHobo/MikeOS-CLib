#ifndef MOSCLIB_HAS_FILE
#define MOSCLIB_HAS_FILE

struct __iobuffer {
	int size;
	int offset;
	char *data;
};


typedef struct __file_s {
	int (*read)();
	int (*write)(char);
	struct __iobuffer ibuf;
} FILE;

extern FILE console;
extern FILE *stdout;
extern FILE *stdin;
extern FILE *stderr;

#define EOF -1

#endif
