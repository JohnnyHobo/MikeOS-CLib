asm("%include 'mikedev.inc'");
asm("%include 'oscall/misc.asm'");

int os_get_api_version()
{
	asm("OSCALL_GET_API_VERSION");
}

void os_pause(int time)
{
	asm("OSCALL_PAUSE");
}

void os_fatal_error(char *error)
{
	asm("OSCALL_FATAL_ERROR");
}

