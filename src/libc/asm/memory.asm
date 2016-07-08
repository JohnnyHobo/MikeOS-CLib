bits 16

GLOBAL _memcpy
GLOBAL _memset
GLOBAL _memcmp
GLOBAL _memchr
GLOBAL _memmove


_memcpy:
	push bp
	mov bp, sp

	push si
	push di

	mov di, [bp + 4]
	mov si, [bp + 6]
	mov cx, [bp + 8]
	cld
	rep movsb
	
	mov ax, [bp + 4]

	pop di
	pop si

	leave
	ret



_memset:
	push bp
	mov bp, sp
	push di

	mov di, [bp + 4]
	mov al, [bp + 6]
	mov cx, [bp + 8]
	cld
	rep stosb
	mov ax, [bp + 4]

	pop di
	leave
	ret



_memcmp:
	push bp
	mov bp, sp

	push si
	push di

	mov si, [bp + 4]
	mov di, [bp + 6]
	mov cx, [bp + 8]
	cld
	repe cmpsb
	je .equal
	ja .greater

	mov ax, -1

.done:
	pop di
	pop si

	leave
	ret

.greater:
	mov ax, 1
	jmp .done

.equal:
	mov ax, 0
	jmp .done
	


_memchr:
	push bp
	mov bp, sp

	push di

	mov di, [bp + 4]
	mov al, [bp + 6]
	mov cx, [bp + 8]
	cld
	repne scasb
	jne .not_found

	dec di
	mov ax, di

.done:
	pop di
	leave
	ret

.not_found:
	mov ax, 0
	jmp .done


_memmove:
	push bp
	mov bp, sp

	push si
	push di

	mov di, [bp + 4]
	mov si, [bp + 6]
	mov cx, [bp + 8]

	; If the destination is greater than the source, copy backwards.
	cmp si, di
	jb .backwards

	cld
	rep movsb

.done:
	pop di
	pop si
	leave
	ret


.backwards:
	; Start at the end to avoid overwriting the source data.
	std
	add di, cx
	dec di
	add si, cx
	dec si

	rep movsb

	cld
	jmp .done


	
