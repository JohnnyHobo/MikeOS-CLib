%macro OSCALL_RUN_BASIC 0
	push bx
	push si
	mov ax, [bp + 4]
	mov bx, [bp + 6]
	mov si, [bp + 8]
	call os_run_basic
	pop si
	pop bx
%endmacro
