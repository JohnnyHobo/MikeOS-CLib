#ifndef MOSCLIB_HAS_PORTS
#define MOSCLIB_HAS_PORTS

/** \brief Send data to an I/O port.
  * \param port The port number.
  * \param data The data to send.
  */
void os_port_byte_out(int port, char data);


/** \brief Retrieve data from an I/O port.
  * \param port The port number to recieve from.
  * \return Data from the port.
  */
char os_port_byte_in(int port);


/** Baud rates for the serial port. */
enum SERIAL_MODE {
	SERIAL_9600_BAUD,	/**< 9600 Baud "normal" mode. */
	SERIAL_1200_BAUD	/**< 1200 Baud "slow" mode. */
};

/** An error occurred if this bit is set in any serial return value. */
#define SERIAL_ERROR 0x80

/** \brief Initialise the serial port.
  * \param mode The mode to use. Make sure the reciever is using the same.
  * \return A result code. The SERIAL_ERROR bit is set if an error occurred.
  */
char os_serial_port_enable(enum SERIAL_MODE mode);

/** \brief Transmit 7-bit data from this machine through the serial port.
  * \param data The data to send.
  * \return A result code. The SERIAL_ERROR bit is set if an error occurred.
  *
  * Be sure the enable the serial port with \ref os_serial_enable() first.
  */
char os_send_via_serial(char data);

/** \brief Recieve 7-bt data to this machine from the serial port.
  * \param The location to store the recieved data.
  * \return A result code. The SERIAL_ERROR bit is set if an error occurred.
  * 
  * The recieved data is only valid if that result code does not indicate an
  * error occurred.
  * Be sure the enable the serial port with \ref os_serial_enable() first.
  */
char os_get_via_serial(char *recieved);

#endif

