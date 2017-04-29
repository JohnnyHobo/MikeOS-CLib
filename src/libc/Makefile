OBJECTS = print.o exit.o conv.o math.o string.o asm/memory.o asm/string.o 
OBJECTS += asm/math.o fs.o memory.o stream.o console.o file.o

all: $(OBJECTS)
	smlrcc -flat32 -c -o libc.a $(OBJECTS)
	cp libc.a ../../lib/libc.a
	
%.o : %.c;
	smlrcc -unreal -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf32 -i../../include -o $@ $*.asm


