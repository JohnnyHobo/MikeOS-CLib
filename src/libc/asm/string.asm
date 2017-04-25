bits 16

GLOBAL _strcmp
GLOBAL _strncat

_strcmp:
	push bp
	mov bp, sp

	push si
	push di

	mov di, [bp + 4]
	mov al, 0
	mov cx, -1
	cld
	repne scasb

	sub di, [bp + 4]
	mov cx, di
	
	mov si, [bp + 4]
	mov di, [bp + 6]
	repe cmpsb

	mov al, [si - 1]
	cmp al, [di - 1]

	ja .higher
	jb .lower

	mov ax, 0
.finish:
	pop di
	pop si

	leave
	ret

.higher:
	mov ax, 1
	jmp .finish

.lower:
	mov ax, -1
	jmp .finish


_strncat:
	push bp
	mov bp, sp

	push si
	push di

	mov si, [bp + 6]
	mov cx, -1
	mov al, 0
	cld
	repne scasb

	mov di, si

	mov si, [bp + 4]
	mov cx, [bp + 8]
	mov al, 0
	repne scasb

	mov cx, si
	sub cx, [bp + 4]
	dec cx

	mov si, [bp + 6]
	mov di, [bp + 4]
	rep movsb

	mov al, 0
	stosb

	pop di
	pop si

	mov ax, [bp + 4]

	leave
	ret

