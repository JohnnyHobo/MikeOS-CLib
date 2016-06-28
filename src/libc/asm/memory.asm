GLOBAL _memcpy
GLOBAL _memset
GLOBAL _memcmp
GLOBAL _memchr


_memcpy:
	push bp
	mov bp, sp

	push si
	push di

	mov di, [bp + 4]
	mov si, [bp + 6]
	mov cx, [bp + 8]
	rep movsb
	
	mov ax, [bp + 4]

	pop di
	pop si

	pop bp
	ret



_memset:
	push bp
	mov bp, sp
	push di

	mov di, [bp + 4]
	mov al, [bp + 6]
	mov cx, [bp + 8]
	rep stosb
	mov ax, [bp + 4]

	pop di
	pop bp
	ret



_memcmp:
	push bp
	mov bp, sp

	push si
	push di

	mov si, [bp + 4]
	mov di, [bp + 6]
	mov cx, [bp + 8]
	repe cmpsb
	je .equal

	mov al, [si]
	cmp al, [di]
	ja .greater

	mov ax, -1

.done:
	pop di
	pop si

	pop bp
	ret

.greater:
	mov ax, 1
	je .done

.equal:
	mov ax, 0
	je .done
	


_memchr:
	push bp
	mov bp, sp

	push di

	mov di, [bp + 4]
	mov al, [bp + 6]
	mov cx, [bp + 8]
	repne scasb
	jne .not_found

	dec di
	mov ax, di

.done:
	pop di
	pop bp
	ret

.not_found:
	mov ax, 0
	jmp .done

