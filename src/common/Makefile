OBJECTS = asm/crt0.o

all: $(OBJECTS)
	cp asm/crt0.o ../../lib/crt0.o

%.o : %.c;
	smlrcc -unreal -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf32 -i../../include -o $@ $*.asm


