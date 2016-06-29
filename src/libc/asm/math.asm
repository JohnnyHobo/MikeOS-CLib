bits 16

GLOBAL _div

_div:
	push bp
	mov bp, sp

	push bx
	mov bx, [bp + 4]

	mov ax, [bp + 6]
	cwd

	mov cx, [bp + 8]
	idiv cx
	
	mov [bx], ax
	mov [bx + 2], dx

	pop bx

	leave
	ret

	
	
