; Library entry point

%define REGISTER_COUNT	10
%define COMMAND_MAX	2

libfloat_base_address:

libfloat_magic				dw 0x2356
libfloat_entry_point			dw libfloat_entry
libfloat_command_register		dw 0
libfloat_data_registers			times REGISTER_COUNT dw 0


libfloat_entry:
	pusha
	push fs
	
	cmp ax, COMMAND_MAX
	jge .invalid
	
	call .get_addr:
.get_addr:
	pop bx
	sub bx, libfloat_entry.get_addr - libfloat_base_address
	
	mov fs, bx
	
	mov si, [bx + libfloat_command_register]
	mov bp, [bx + libfloat_data_registers]
	
	call near [bx + si + libfloat_command_pointers]
	
.invalid
	pop fs
	popa
	ret
	
	
libfloat_command_pointers:
	dw	libfloat_truncate
	
	