%include 'lib/memory.asm'

%macro LIBCALL_MEMORY_INITIALISE 0
	push si
	mov si, [bp+4]
	mov ax, [bp+6]
	call memory_initialise

	mov ah, 0
	setc al

	pop si
%endmacro

%macro LIBCALL_MEMORY_ALLOCATE 0
	push si
	mov ax, [bp+4]
	call memory_allocate
	jc %%error

	mov ax, si
	jmp %%done

	%%error:
	mov ax, 0
	pop si

	%%done:
%endmacro

%macro LIBCALL_MEMORY_FREE 0
	push si
	mov si, [bp+4]
	call memory_free
	pop si
%endmacro
	
