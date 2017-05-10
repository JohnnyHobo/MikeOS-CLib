bits 16

; div_t div(int numerator, int denominator);
GLOBAL _div

_div:
	push ebp
	movzx ebp, sp

	push ebx
	mov ebx, [ebp + 8]	; Structure implicitly passed on the stack.

	mov eax, [ebp + 12]	; Numerator
	cdq

	mov ecx, [ebp + 16]	; Denominator
	idiv ecx
	
	mov [ebx], eax
	mov [ebx + 4], edx

	pop ebx

	o32 leave
	retf

	
	
