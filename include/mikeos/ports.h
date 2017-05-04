#ifndef MOSCLIB_HAS_PORTS
#define MOSCLIB_HAS_PORTS
void os_port_byte_out(int port, char data);
char os_port_byte_in(int port);
#define SERIAL_9600_BAUD 0
#define SERIAL_1200_BAUD 1
#define SERIAL_ERROR 0x80
char os_serial_port_enable(int mode);
char os_send_via_serial(char data);
char os_get_via_serial(char *recieved);
#endif

