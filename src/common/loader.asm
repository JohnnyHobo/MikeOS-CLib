

















































%include 'src/mikeos/mikedev.inc'

bits 16
org 32768

start:
	xchg bx, bx
	push ds
	push es

	mov ax, ss
	mov [os_ss], ax
	mov [os_sp], sp

	cmp word [file_start + 0x00], 0x5A4D
	jne invalid_program

	mov ax, 0x3000
	mov es, ax

	mov si, file_start
	mov di, 0
	mov cx, file_end - file_start
	rep movsb

	mov ax, 0x3000

	add ax, [file_start + 0x08]
	mov bx, ax
	add bx, [file_start + 0x0E]
	mov ss, bx
	mov sp, [file_start + 0x10]

	add ax, [file_start + 0x16]
	push ax
	push word [file_start + 0x14]

	mov ax, 0x3000
	mov ds, ax

	retf
	






invalid_program:
	mov si, errormsg.header
	jmp error

error:
	cli
	mov ax, [os_ss]
	mov ss, ax
	mov sp, [os_sp]
	sti

	call os_print_string
	call os_print_newline

	ret
	


errormsg:
	.header db 'Invalid Header', 0

os_ss	dw 0
os_sp	dw 0

file_start:
incbin 'src/common/exefile.dat'
file_end:
