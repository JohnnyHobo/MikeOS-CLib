GLOBAL _div

_div:
	push bp
	mov bp, sp

	mov ax, [bp + 4]
	mov dx, 0

	mov cx, [bp + 6]
	div cx
	
	mov [div_result], ax
	mov [div_modulo], dx

	mov ax, div_result

	pop bp
	ret

div_result dw 0
div_modulo dw 0
	
	
