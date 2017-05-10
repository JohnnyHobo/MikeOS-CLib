OBJECTS = crt0.o asm/c0du.o

all: $(OBJECTS)
	cp crt0.o ../../lib/crt0.o
	cp asm/c0du.o ../../lib/c0du.o

%.o : %.c;
	smlrcc -unreal -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf -i../../include -o $@ $*.asm


