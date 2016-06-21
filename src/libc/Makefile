OBJECTS = print.o asm/start.o exit.o conv.o math.o string.o

all: $(OBJECTS)
	smlrcc -flat16 -c -o libc.a $(OBJECTS)
	
%.o : %.c;
	smlrcc -tiny -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf -i../../include -o $@ $*.asm


