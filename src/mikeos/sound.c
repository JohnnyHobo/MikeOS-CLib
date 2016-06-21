asm("%include 'mikedev.inc'");
asm("%include 'oscall/sound.asm'");

void os_speaker_tone(int divisor)
{
	asm("OSCALL_SPEAKER_TONE");
}

void os_speaker_off()
{
	asm("OSCALL_SPEAKER_OFF");
}

