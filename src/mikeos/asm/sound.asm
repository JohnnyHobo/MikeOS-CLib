bits 16

%include 'mikedev.inc'
%include 'macros.inc'


; void os_speaker_tone(int divisor);
GLOBAL _os_speaker_tone

_os_speaker_tone:
	START_API

	mov ax, [ebp + 8]		; `divisor`
	MOSCALL os_speaker_tone

	END_API

	
; void os_speaker_off();
GLOBAL _os_speaker_off

_os_speaker_off:
	START_API

	MOSCALL os_speaker_off

	END_API

	

