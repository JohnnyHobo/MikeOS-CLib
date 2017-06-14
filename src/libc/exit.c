void _exit();

void exit(int status)
{
	/* See the file 'crt0.c' */
	_Exit();
}

void abort()
{
	_Exit();
}


