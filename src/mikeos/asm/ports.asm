bits 16

%include 'mikedev.inc'
%include 'macros.inc'


; void os_port_byte_out(int port, char data);
GLOBAL _os_port_byte_out

_os_port_byte_out:
	START_API

	mov dx, [ebp + 8]
	mov al, [ebp + 12]
	MOSCALL os_port_byte_out

	END_API

	
; char os_port_byte_in(int port);
GLOBAL _os_port_byte_in

_os_port_byte_in:
	START_API

	mov dx, [ebp + 8]		; `port`
	MOSCALL os_port_byte_in

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

	

