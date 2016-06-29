OBJECTS = print.o exit.o conv.o math.o string.o asm/memory.o 
OBJECTS += asm/math.o fs.o memory.o

all: $(OBJECTS)
	smlrcc -flat16 -c -o libc.a $(OBJECTS)
	cp libc.a ../../lib/libc.a
	
%.o : %.c;
	smlrcc -tiny -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf -i../../include -o $@ $*.asm


