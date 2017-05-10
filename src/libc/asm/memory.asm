bits 16


; void *memcpy(void *destination, void *source, size_t num);
GLOBAL _memcpy

_memcpy:
	push ebp
	movzx ebp, sp

	push esi
	push edi

	mov edi, [ebp + 8]
	mov esi, [ebp + 12]
	mov ecx, [ebp + 16]
	cld
	rep a32 movsb
	
	mov eax, [ebp + 8]

	pop edi
	pop esi

	o32 leave
	retf



; void *memset(void *ptr, int value, size_t num);
GLOBAL _memset

_memset:
	push ebp
	movzx ebp, sp

	push edi

	mov edi, [ebp + 8]
	mov al, [ebp + 12]
	mov ecx, [ebp + 16]
	cld
	rep a32 stosb
	mov eax, [ebp + 8]

	pop edi

	o32 leave
	retf


; void *memcmp(void *ptr1, void *ptr2, size_t num);
GLOBAL _memcmp

_memcmp:
	push ebp
	movzx ebp, sp

	push esi
	push edi

	mov esi, [ebp + 8]
	mov edi, [ebp + 12]
	mov ecx, [ebp + 16]
	cld
	repe a32 cmpsb
	je .equal
	ja .greater

	mov eax, -1

.done:
	pop edi
	pop esi

	o32 leave
	retf

.greater:
	mov eax, 1
	jmp .done

.equal:
	mov eax, 0
	jmp .done
	

; void *memchr(void *ptr1, void *ptr2, size_t num);
GLOBAL _memchr

_memchr:
	push ebp
	movzx ebp, sp

	push edi

	mov edi, [ebp + 8]
	mov al, [ebp + 12]
	mov ecx, [ebp + 16]
	cld
	repne a32 scasb
	jne .not_found

	dec edi
	mov eax, edi

.done:
	pop edi
	o32 leave
	retf

.not_found:
	mov eax, 0
	jmp .done


; void *memmove(void *destination, void *source, size_t num);
GLOBAL _memmove

_memmove:
	push ebp
	movzx ebp, sp

	push esi
	push edi

	mov edi, [ebp + 8]
	mov esi, [ebp + 12]
	mov ecx, [ebp + 16]

	; If the destination is greater than the source, copy backwards.
	cmp esi, edi
	jb .backwards

	cld
	rep a32 movsb

.done:
	pop edi
	pop esi
	o32 leave
	retf


.backwards:
	; Start at the end to avoid overwriting the source data.
	std
	add edi, ecx
	dec edi
	add esi, ecx
	dec esi

	cld
	rep a32 movsb

	jmp .done


	
