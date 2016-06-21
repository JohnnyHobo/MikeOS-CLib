#ifndef MOSCLIB_HAS_PORTS
#define MOSCLIB_HAS_PORTS
void os_port_byte_out(int port, char data);
char os_port_byte_in(int port);
char os_serial_port_enable(int mode);
char os_send_via_serial(char data);
char os_get_via_serial(char *recieved);
#endif

