%include 'helper/exponent.asm'
%include 'helper/fraction.asm'

; Input Data:
; 	SI + 0		Floating point input
; Output Data:
;	DI + 0		Integer Part
; 	DI + 4		Fraction Part
libfloat_modf_double:
	pusha
	
	call libfloat_get_exponent
	
	cmp ax, LIBFLOAT_DOUBLE_FRACTION_BITS
	jge .all_int_bits
	
	cmp ax, 0
	jl .all_frac_bits
	
	mov dx, LIBFLOAT_DOUBLE_FRACTION_BITS
	sub dx, ax
	
	
	