%macro OSCALL_GET_API_VERSION 0
	call os_get_api_version
	mov ah, 0
%endmacro

%macro OSCALL_PAUSE 0
	mov ax, [bp+4]
	call os_pause
%endmacro

%macro OSCALL_FATAL_ERROR 0
	mov si, [bp+4]
	call os_fatal_error
%endmacro
