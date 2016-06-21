%macro OSCALL_SPEAKER_TONE 0
	mov ax, [bp+4]
	call os_speaker_tone
%endmacro

%macro OSCALL_SPEAKER_OFF 0
	call os_speaker_off
%endmacro