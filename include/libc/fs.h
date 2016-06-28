#ifndef MOSCLIB_HAS_FS
#define MOSCLIB_HAS_FS

#define L_tmpnam 13
#define NULL 0

int remove(char *filename);
int rename(char *oldname, char *newname);
char *tmpnam(char *str);

#endif
