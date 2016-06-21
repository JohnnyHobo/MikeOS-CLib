; The carry flag usually indicate whether an error occured.
; This is easy to use in assembly, however in C, it should be passed as a
; function return value. i.e. if (!os_load_file("foo.bar"))
; This macro sets the AX register to true if carry was not set or false if it
; was (i.e. an error occurred).
%macro CF_TO_AX 0
	jc %%carry

	mov ax, 1
	jmp %%done

	%%carry:
	mov ax, 0

	%%done:
%endmacro

