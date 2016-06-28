#include "mikeos/disk.h"
#include "libc/fs.h"

char internal_tmp[L_tmpnam];

int remove(char *filename)
{
	return !os_remove_file(filename);
}

int rename(char *oldname, char *newname)
{
	return !os_rename_file(oldname, newname);
}

char *tmpnam(char *str)
{
	int i;

	if (!str) str = internal_tmp;
	
	for (i = 0; i < 8; i++) str[i] = os_get_random('A', 'B');
	str[i] = '.';

	for (i = 8; i < 13; i++) str[i] = os_get_random('0', '9');
	str[i] = 0;
}



