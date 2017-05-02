%macro OSCALL_PORT_BYTE_OUT 0
	mov dx, [bp+4]
	mov al, [bp+6]
	call os_port_byte_out
%endmacro

%macro OSCALL_PORT_BYTE_IN 0
	mov dx, [bp+4]
	call os_port_byte_in
%endmacro

%macro OSCALL_SERIAL_PORT_ENABLE 0
	mov ax, [bp+4]
	call os_serial_port_enable
	mov al, ah
%endmacro

%macro OSCALL_SEND_VIA_SERIAL 0
	mov al, [bp+4]
	call os_send_via_serial
	mov al, ah
%endmacro

%macro OSCALL_GET_VIA_SERIAL 0
	push si
	call os_get_via_serial
	mov si, [bp+4]
	mov [si], al
	mov al, ah
	pop si
%endmacro

