bits 16


; int strcmp(char *str1, char *str2);
GLOBAL _strcmp

_strcmp:
	push ebp
	movzx ebp, sp

	push esi
	push edi

	mov edi, [ebp + 8]
	mov al, 0
	mov ecx, -1
	cld
	repne a32 scasb

	sub edi, [ebp + 8]
	mov ecx, edi
	
	mov esi, [ebp + 8]
	mov edi, [ebp + 12]
	repe a32 cmpsb

	mov al, [esi - 1]
	cmp al, [edi - 1]

	ja .higher
	jb .lower

	mov eax, 0
.finish:
	pop edi
	pop esi

	o32 leave
	retf

.higher:
	mov eax, 1
	jmp .finish

.lower:
	mov eax, -1
	jmp .finish


; char *strncat(char *destination, char *source, size_t num);
GLOBAL _strncat

_strncat:
	push ebp
	movzx ebp, sp

	push esi
	push edi

	; Find the length of the string to add.
	mov edi, [ebp + 12]
	mov ecx, [ebp + 16]
	inc ecx
	mov al, 0
	cld
	repne a32 scasb

	; Remember the last chararacter address.
	mov esi, edi

	; Now find the end of the base string.
	mov edi, [ebp + 8]
	mov ecx, -1
	mov al, 0
	repne a32 scasb
	dec edi

	; Now figure out the length to copy.
	mov ecx, esi
	sub ecx, [ebp + 12]
	dec ecx

	; Copy the new string after the end of the base string.
	mov esi, [ebp + 12]
	rep a32 movsb

	mov al, 0
	a32 stosb

	pop edi
	pop esi

	mov eax, [ebp + 8]

	o32 leave
	retf

