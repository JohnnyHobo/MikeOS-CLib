; Helper routines for dealing with exponents

%include "data/format.asm"

; Input:
; R1		float ptr	Input float pointer
; Output:
; R2		int		Integer exponent value
libfloat_get_exponent:
	pusha
	
	mov  si, [ds:bp + 0]
	
	mov eax, [ds:bp + (LIBFLOAT_FRACTION_BITS / 8)]
	shr eax, LIBFLOAT_FRACTION_BITS - (LIBFLOAT_FRACTION_BITS / 8)
	
	mov ebx, 1 << LIBFLOAT_EXPONENT_BITS
	dec ebx
	
	and eax, ebx
	add eax, LIBFLOAT_EXPONENT_BIAS
	
	
	
	
	
	
	
	
	
	
	