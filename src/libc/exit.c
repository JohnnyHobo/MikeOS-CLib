void _exit();

void exit(int status)
{
	/* See the file 'asm/start.asm' */
	_Exit();
}

void abort()
{
	_Exit();
}


