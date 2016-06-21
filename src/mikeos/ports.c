asm("%include 'mikedev.inc'");
asm("%include 'oscall/ports.asm'");

void os_port_byte_out(int port, char data)
{
	asm("OSCALL_PORT_BYTE_OUT");
}

char os_port_byte_in(int port)
{
	asm("OSCALL_PORT_BYTE_IN");
}

char os_serial_port_enable(int mode)
{
	asm("OSCALL_SERIAL_PORT_ENABLE");
}

char os_send_via_serial(char data)
{
	asm("OSCALL_SEND_VIA_SERIAL");
}

char os_get_via_serial(char *recieved)
{
	asm("OSCALL_GET_VIA_SERIAL");
}
