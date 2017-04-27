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

	; Find the length of the string to add.
	mov di, [bp + 6]
	mov cx, [bp + 8]
	inc cx
	mov al, 0
	cld
	repne scasb

	; Remember the last chararacter address.
	mov si, di

	; Now find the end of the base string.
	mov di, [bp + 4]
	mov cx, -1
	mov al, 0
	repne scasb
	dec di

	; Now figure out the length to copy.
	mov cx, si
	sub cx, [bp + 6]
	dec cx

	; Copy the new string after the end of the base string.
	mov si, [bp + 6]
	rep movsb

	mov al, 0
	stosb

	pop di
	pop si

	mov ax, [bp + 4]

	leave
	ret

