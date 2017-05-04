bits 16

%include 'mikedev.inc'
%include 'macros.inc'

section .text

; int length = os_string_length(char *str);
; This is reimplemented	in the library.
GLOBAL _os_string_length

_os_string_length:
	START_API

	mov edi, [ebp + 8]
	mov al, 0
	mov ecx, -1
	repne a32 scasb

	sub edi, [ebp + 8]
	dec edi

	mov eax, edi
	END_API

	
; int position = os_find_char_in_string(char *str, char to_find);
GLOBAL _os_find_char_in_string

_os_find_char_in_string:
	START_API

	RELOC_STR 0
	
	mov si, [ebp - 10]		; `str` (duplicated)
	mov al, [ebp + 12]		; `to_find`
	MOSCALL os_find_char_in_string
	movzx eax, ax

	END_API

	
; char *os_string_reverse(char *str);
GLOBAL _os_string_reverse

_os_string_reverse:
	START_API

	RELOC_STR 0

	mov si, [ebp - 10]		; `str`
	MOSCALL os_string_reverse

	RESTORE_STR si, [ebp + 8]
	mov eax, [ebp + 8]

	END_API

	
; char *os_string_charchange(char *str, char to_find, char replacement);
GLOBAL _os_string_charchange

_os_string_charchange:
	START_API
	push bx

	RELOC_STR 0
	
	mov si, [ebp - 12]		; `str` (duplicated)
	mov al, [ebp + 12]		; `to_find`
	mov bl, [ebp + 16]		; `replacement`
	MOSCALL os_string_charchange

	RESTORE_STR si, [ebp + 8]
	mov eax, [ebp + 8]

	mov bx, [ebp - 10]
	END_API

	
; char *os_string_uppercase(char *str);
GLOBAL _os_string_uppercase

_os_string_uppercase:
	START_API

	RELOC_STR 0
	
	mov ax, [ebp - 10]		; `str` (duplicated)
	MOSCALL os_string_uppercase

	RESTORE_STR ax, [ebp + 8]
	mov eax, [ebp + 8]

	END_API

	
; char *os_string_lowercase(char *str);
GLOBAL _os_string_lowercase

_os_string_lowercase:
	START_API

	RELOC_STR 0

	mov ax, [ebp - 10]		; `str` (duplicated)
	MOSCALL os_string_lowercase

	RESTORE_STR ax, [ebp + 8]
	mov eax, [ebp + 8]

	END_API

	
; char *os_string_copy(char *src, char *dest);
; This is reimplemented in the library.
GLOBAL _os_string_copy

_os_string_copy:
	START_API

	mov esi, [ebp + 8]
	mov edi, [ebp + 12]

.next:
	a32 lodsb
	a32 stosb
	cmp al, 0
	jne .next

	mov eax, [ebp + 12]
	END_API
	

; char *os_string_truncate(char *str, int length);
GLOBAL _os_string_truncate

_os_string_truncate:
	START_API

	RELOC_STR 0

	mov si, [ebp - 10]
	mov ax, [ebp + 12]
	MOSCALL os_string_truncate

	RESTORE_STR si, [ebp + 8]
	mov eax, [ebp + 8]

	END_API

	
; char *os_string_join(char *str1, char *str2, char *dest);
GLOBAL _os_string_join

_os_string_join:
	START_API
	push bx

	RELOC_STR 0
	RELOC_STR 1
	ALLOC_DATA 1024

	mov ax, [ebp - 12]
	mov bx, [ebp - 14]
	mov cx, [ebp - 16]
	MOSCALL os_string_join

	RESTORE_STR cx, [ebp + 16]
	mov eax, [ebp + 16]

	mov bx, [ebp - 10]
	END_API

	
; char *os_string_chomp(char *str);
GLOBAL _os_string_chomp

_os_string_chomp:
	START_API

	RELOC_STR 0

	mov ax, [ebp - 10]
	MOSCALL os_string_chomp

	RESTORE_STR ax, [ebp + 8]
	mov eax, [ebp + 8]

	END_API

	
; char *os_string_strip(char *str, char to_remove);
GLOBAL _os_string_strip

_os_string_strip:
	START_API

	RELOC_STR 0

	mov si, [ebp - 10]
	mov al, [ebp + 12]
	MOSCALL os_string_strip
	
	RESTORE_STR si, [ebp + 8]
	mov eax, [ebp + 8]

	END_API

	
; int os_string_compare(const char *str1, const char *str2);
GLOBAL _os_string_compare

_os_string_compare:
	START_API

	RELOC_STR 0
	RELOC_STR 1

	mov si, [ebp - 10]
	mov di, [ebp - 12]
	MOSCALL os_string_compare
	
	setc al
	movzx eax, al
	END_API

	
; int os_string_strincmp(const char *str1, const char *str2, int num_chars);
GLOBAL _os_string_strincmp

_os_string_strincmp:
	START_API

	RELOC_STR 0
	RELOC_STR 1

	mov si, [ebp - 10]		; `str1` (duplicated)
	mov di, [ebp - 12]		; `str2` (duplicated)
	mov cl, [ebp + 16]		; `num_chars`
	MOSCALL os_string_strincmp

	setc al
	movzx eax, al
	END_API

	
; void os_string_parse(char *src, char **str1, char **str2, char **str3, char **str4);
GLOBAL _os_string_parse

_os_string_parse:
	START_API
	push bx

	RELOC_STR 0

	push dword [ebp + 8]
	UMCALL _os_string_length
	inc eax
	push eax

	mov si, [ebp - 12]		; `src` (duplicated)
	MOSCALL os_string_parse
	xchg bx, bx

	RESTORE_DATA si, [ebp - 20], [ebp + 8]

	mov edi, [ebp + 8]

	; FIXME: SS =/= DS
	sub ax, [ebp - 12]
	movzx eax, ax
	add eax, edi
	mov esi, [ebp + 12]
	mov [esi], eax

	sub bx, [ebp - 12]
	movzx eax, bx
	add eax, edi
	mov esi, [ebp + 16]
	mov [esi], eax

	sub cx, [ebp - 12]
	movzx eax, cx
	add eax, edi
	mov esi, [ebp + 20]
	mov [esi], eax

	sub dx, [ebp - 12]
	movzx eax, dx
	add eax, edi
	mov esi, [ebp + 24]
	mov [esi], eax

	mov bx, [ebp - 10]
	END_API

	
; short os_string_to_int(char *str);
GLOBAL _os_string_to_int

_os_string_to_int:
	START_API

	RELOC_STR 0

	mov si, [ebp - 10]
	MOSCALL os_string_to_int

	END_API

	
; const char *os_int_to_string(unsigned short value);
GLOBAL _os_int_to_string

_os_int_to_string:
	START_API

	mov ax, [ebp + 8]
	MOSCALL os_int_to_string

	RESTORE_STR ax, int_string_buffer
	mov eax, int_string_buffer	

	END_API

	
; const char *os_sint_to_string(signed short value);
GLOBAL _os_sint_to_string

_os_sint_to_string:
	START_API

	mov ax, [ebp + 8]
	MOSCALL os_sint_to_string

	RESTORE_STR ax, sint_string_buffer
	mov eax, sint_string_buffer

	END_API

	
; char *os_long_int_to_string(long longint, int base, char *buffer);
GLOBAL _os_long_int_to_string

_os_long_int_to_string:
	START_API
	push bx 

	ALLOC_DATA 12

	mov ax, [ebp + 8]	; Lower half of `longint`
	mov dx, [ebp + 10]	; Higher half of `longint`
	mov bx, [ebp + 12]	; `base`
	mov di, [ebp - 12]	; Low memory buffer (12)
	MOSCALL os_long_int_to_string

	RESTORE_STR di, [ebp + 16] ; Copy output to `buffer`
	mov eax, [ebp + 16]	; Return `buffer`

	mov bx, [ebp - 10]
	END_API

	
; void os_set_time_fmt(int format);
GLOBAL _os_set_time_fmt

_os_set_time_fmt:
	START_API

	mov al, [ebp + 8]	; `flags`
	MOSCALL os_set_time_fmt

	END_API

	
; char *os_get_time_string(char *buffer);
GLOBAL _os_get_time_string

_os_get_time_string:
	START_API
	push bx

	ALLOC_DATA 20

	mov bx, [ebp - 12]		; Low memory buffer
	MOSCALL os_get_time_string

	RESTORE_STR bx, [ebp + 8]

	mov bx, [ebp - 10]
	END_API

	
; void os_set_date_fmt(int format);
GLOBAL _os_set_date_fmt

_os_date_format:
	START_API

	ALLOC_DATA 20

	mov al, [ebp + 8]	; `flags`
	MOSCALL os_set_date_fmt

	END_API

	
; char *os_get_date_string(char *buffer);
GLOBAL _os_get_date_string

_os_get_date_string:
	START_API
	push bx

	ALLOC_DATA 20

	mov bx, [ebp - 10]		; Low memory buffer (20)
	MOSCALL os_get_date_string

	RESTORE_STR bx, [ebp + 8]	; Copy to `buffer`
	mov eax, [ebp + 8]

	mov bx, [ebp - 10]
	END_API

	
section .bss
	int_string_buffer	resb 6
	sint_string_buffer	resb 7

