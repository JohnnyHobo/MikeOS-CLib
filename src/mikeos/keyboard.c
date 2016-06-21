asm("%include 'mikedev.inc'");
asm("%include 'oscall/keyboard.asm'");

int os_wait_for_key()
{
	asm("OSCALL_WAIT_FOR_KEY");
}

int os_check_for_key()
{
	asm("OSCALL_CHECK_FOR_KEY");
}
