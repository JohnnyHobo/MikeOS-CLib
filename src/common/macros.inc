%ifndef MOSCLIB_HAS_COMMON_MACROS
%define MOSCLIB_HAS_COMMON_MACROS

; Unreal Mode CALL
; A call macro that works properly with relocation.
; e.g. UMCALL _main

%macro UMCALL 1
	section .text
	db 0x9A		; The far call instruction
	%%offset: dd %1	; The location to be called

	section .relot	; Add an entry on the relocation table for the target.
	dd %%offset

	section .text
%endmacro

%endif
