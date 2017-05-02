%include 'src/mikeos/mikedev.inc'

bits 16
org 32768

%define MAX_PARAMS 10

jmp short start

loader:
	.argc			dw 0
	.argv			dw argv0
	.exitptr		dw exit
	.os_cs			dw 0
	.os_ds			dw 0
	.os_ss			dw 0
	.os_sp			dw 0
	.ldroffs		dw $$
	.os_call		dw oscall_handler
	.lowmem_start		dw file_start
	

times 32-($-$$) db 0


start:
	push ds
	push es
	push fs
	push gs

	; Remember initial stack, it will be needed to return from the program.
	mov ax, ss
	mov [loader.os_ss], ax
	mov [loader.os_sp], sp

	mov ax, cs
	mov [loader.os_cs], ax
	mov ax, ds
	mov [loader.os_ds], ax

	; Program start routine --- called directly by the OS

	; The operating system should have passed SI as the parameters.
	; The string is converted into an array of parameters.

	; A zero value indicates no parameters
	cmp si, 0
	je .no_parameters

	; It may also be indicated by a blank string
	cmp byte [si], 0
	je .no_parameters
	
	mov bx, param_array
	mov cx, MAX_PARAMS
	mov dx, 1

.get_parameter:
	mov [bx], si
	add bx, 2

	mov al, ' '
	call os_string_tokenize

	cmp di, 0
	je .args_done

	inc dx
	mov si, di
	loop .get_parameter

.args_done:
	mov [loader.argc], dx
	mov word [bx], 0
	jmp start_exe

.no_parameters:
	mov dx, 1
	jmp .args_done
	

start_exe:
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

	push dword loader + 0x20000

	add ax, [file_start + 0x16]
	push ax
	push word [file_start + 0x14]

	mov ax, 0x3000
	mov ds, ax

	retf


; oscall_handler(short dataseg, short address)
; Calls a local function from unreal mode.
oscall_handler:
	push bp
	mov bp, sp

	push ds
	push es

	push ax
	; TODO: Fix this offset
	mov ax, [bp + 4]
	mov ds, ax
	mov es, ax
	pop ax

	call near [bp + 6]

	pop es
	pop ds
	leave
	retf
	

invalid_program:
	mov si, errormsg.header
	jmp error

exit:
	pop gs
	pop fs
	pop es
	pop ds
	ret


error:
	cli
	mov ax, [loader.os_ss]
	mov ss, ax
	mov sp, [loader.os_sp]
	sti

	call os_print_string
	call os_print_newline

	pop gs
	pop fs
	pop es
	pop ds
	ret
	


errormsg:
	.header db 'Invalid Header', 0

argv0				dw 0
param_array			times MAX_PARAMS + 1 dw 0
argc				dw 0


file_start:
incbin 'src/common/exefile.dat'
file_end:
