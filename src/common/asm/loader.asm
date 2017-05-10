%include 'src/mikeos/mikedev.inc'
%include 'src/common/dosexe.inc'

bits 16
org 32768

%define LOAD_SEGMENT 0x3000

%define MAX_PARAMS 10

; This file contains code put at the start of the EXE file.
; It performs a few functions before starting the main program:
;  * Converts the OS's command line parameters in C's argc,argv format.
;  * Tells the memory manager where to put allocated data.
;  * Tells the OS wrappers where to copy data so the OS can read it.
;  * Provides a function to make OS calls at runtime.
;  * Provides a function to return to the OS.
;
; This code remains in memory while the main program is running.

; Code is run in this order:
;  * start (asm/loader.asm) --- This file, collects data and starts the EXE
;  * __start (asm/c0du.asm) --- Smaller C relocator / unreal mode startup.
;  * ___start__ (crt0.c) --- Sets up for the main program.
;  * _main (program) --- Executes the main program.
;  * __Exit (crt0.c) --- Returns to the OS environment.
;  * exit (asm/loader.asm) --- Returns control to the OS.


; Jump over the loader's data block.
jmp short start
db 'MU'

loader:
	.argc			dd 0
	.argv			dd argv0
	.exitptr		dd exit
	.segoffs		dd 0
	.os_stack		dd 0
	.os_call		dd oscall_handler
	.os_ds			dd 0
	.lowmem_start		dd file_end
	.lowmem_size		dd 0x10000
	.highmem_start		dd 0x100000
	.highmem_size		dd 0x800000	; TODO: Get actual memory size
	

times 64-($-$$) db 0


start:
	push ds
	push es
	push fs
	push gs

	; Remember initial stack, it will be needed to return from the program.
	mov ax, ss
	mov [loader.os_stack + 2], ax
	mov [loader.os_stack + 0], sp

	mov cx, cs
	mov dx, ds
	movzx ebx, dx
	shl ebx, 4

	; Add segment to code addresses.
	mov [loader.os_call + 2], cx
	mov [loader.exitptr + 2], cx

	; Remember the data segment and it's absolute offset.
	mov [loader.os_ds], dx
	mov [loader.segoffs], ebx

	; Convert segmented data addresses to flat.
	add [loader.argv], ebx
	add [loader.lowmem_start], ebx

	sub word [loader.lowmem_size], file_end

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
	movzx eax, si
	add eax, [loader.segoffs]
	mov [bx], eax
	add bx, 4

	inc dx

	mov al, ' '
	call os_string_tokenize

	cmp di, 0
	je .args_done

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
	; Check is the EXE's magic number is correct.
	; Otherwise the file is corrupted and can't be loaded.
	cmp word [file_start + EXE_MAGIC], EXE_MAGIC_VAL
	jne invalid_program

	; DS and ES need to be set to the segment the program is to be loaded.
	; Just set ES for now, this allows copying data with stosb/movsb but
	; still allows data to be retrieved from this segment.
	mov ax, LOAD_SEGMENT
	mov es, ax

	; Copy the exe file inside this binary into it's own space.
	mov si, file_start
	mov di, 0
	mov cx, file_end - file_start
	rep movsb

	; Find the base segment for the EXE.
	; The other segments in the EXE are offsets from this.
	; base_seg = load_seg + header_size 
	mov ax, LOAD_SEGMENT
	add ax, [file_start + EXE_HEADER_SIZE]

	; Find and set the new stack.

	; First figure out the new stack segment.
	; stack_seg = base_seg + ss_offset
	mov bx, ax
	add bx, [file_start + EXE_STACK_SEG]
	cli
	mov ss, bx
	
	; Now, set the stack pointer to the one given.
	mov sp, [file_start + EXE_STACK_PTR]
	sti

	; Convert the loader's data address to a flat 32-bit address and push
	; the address onto the new stack.
	; The address of the data will eventually be passed to ___start__
	mov edx, loader
	add edx, [loader.segoffs]
	push edx

	; Figure out the new code segment and push it onto the stack.
	; code_seg = base_reg + cs_offset
	add ax, [file_start + EXE_ENTRY_CS]
	push ax
	; Also push the starting address for the EXE.
	push word [file_start + EXE_ENTRY_IP]

	; Finally set the correct data segment.
	mov ax, LOAD_SEGMENT
	mov ds, ax

	; Jump the the segment and address just pushed onto the stack and 
	; begin the EXE. The will run the __start code in 'asm/c0du.asm'
	retf


; Calls a local function from unreal mode.
; oscall_handler(short dataseg, short address)
oscall_handler:
	push bp
	mov bp, sp

	push ds
	push es

	push ax
	mov ax, [bp + 6]
	mov ds, ax
	mov es, ax
	pop ax

	call near [bp + 8]

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
	mov ax, [loader.os_stack + 2]
	mov ss, ax
	mov sp, [loader.os_stack + 0]
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

argv0				dd 0
param_array			times MAX_PARAMS + 1 dd 0


file_start:
incbin 'src/common/exefile.dat'
file_end:
