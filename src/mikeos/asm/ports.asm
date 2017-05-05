bits 16

%include 'mikedev.inc'
%include 'macros.inc'


; void os_port_byte_out(int port, char data);
; Reimplemented	in library.
GLOBAL _os_port_byte_out

_os_port_byte_out:
	START_API

	mov dx, [ebp + 8]		; `port`
	mov al, [ebp + 12]		; `char`
	out dx, al

	END_API

	
; char os_port_byte_in(int port);
; Reimplemented	in library.
GLOBAL _os_port_byte_in

_os_port_byte_in:
	START_API

	mov dx, [ebp + 8]		; `port`
	in al, dx

	movzx eax, al
	END_API

	
; char os_serial_port_enable(int mode);
GLOBAL _os_serial_port_enable

_os_serial_port_enable:
	START_API

	mov ax, [ebp + 8]		; `mode`
	MOSCALL os_serial_port_enable
	movzx eax, al

	END_API

	
; char os_send_via_serial(char data);
GLOBAL _os_send_via_serial

_os_send_via_serial:
	START_API

	mov al, [ebp + 8]		; `data`
	MOSCALL os_send_via_serial
	movzx eax, al

	END_API

	
; char os_get_via_serial(char *recieved);
GLOBAL _os_get_via_serial

_os_get_via_serial:
	START_API

	MOSCALL os_get_via_serial
	
	mov esi, [ebp + 8]
	mov [esi], al

	movzx eax, ah
	END_API

	

