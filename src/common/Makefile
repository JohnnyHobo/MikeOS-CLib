OBJECTS = asm/crt0.o asm/crt0_s.o

all: $(OBJECTS)
	cp asm/crt0.o ../../lib/crt0.o
	cp asm/crt0_s.o ../../lib/crt0_s.o

%.o : %.c;
	smlrcc -tiny -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf -i../../include -o $@ $*.asm


