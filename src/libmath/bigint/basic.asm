

; R1 - Bytes in Value A
; R2 - Pointer to Value A
; R3 - Bytes in Value B
; R4 - Pointer to Value B
; R5 - Bytes in Result Buffer
; R6 - Pointer to Result Buffer
; R7 - Status
libmath_add_bigint:
	mov si, [R2]
	mov di, [R4]
	mov bx, [R6]
	
	; Find the smallest register width out of Value A, Value B and Result
	mov ax, [R3]
	
	cmp ax, [R1]
	jb .use_val_a_size
	
.check_result_size:
	cmp ax, [R5]
	jb .use_result_size
	
.set_final_size:
	mov cx, ax
	jcxz .done
	
	xor dx, dx
	
	cmp cx, 3
	jbe .sum_16_bits
	
	movzx eax, dx
	xor dx, dx
	
	adc eax, [si]
	jc .inital_carry
.add_values:
	adc eax, [di]
	jc .sum_carry
	
.store_result:
	mov [bx], eax
	jcxz .done
	
	
.initial_carry:
	mov dx, 1
	jmp .add_values
	
.store_result:
	mov dx, 1
	jmp .add_values
	
	
	
.use_val_a_size:
	mov ax, [R1]
	jmp .check_result_size
	
.use_result_size:
	mov ax, [R5]
	jmp .set_final_size
	
	
.sum_16_bits:
	cmp cx, 2
	jb .sum_8_bits
	
	