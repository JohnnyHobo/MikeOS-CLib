#ifndef MOSCLIB_HAS_EXIT
#define MOSCLIB_HAS_EXIT

#define EXIT_SUCCESS	1
#define EXIT_FAILURE	0

void exit(int status);
void abort();
void _Exit();

#endif
