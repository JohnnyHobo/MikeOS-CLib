OBJECTS = memory.o

all: $(OBJECTS)
	smlrcc -flat32 -c -o libmemory.a $(OBJECTS)
	cp libmemory.a ../../lib/libmemory.a
	
%.o : %.c;
	smlrc -unreal $*.c $*.asm
	nasm -f elf32 -o $@ $*.asm 
	
%.o : %.asm;
	nasm -f elf32 -o $@ $*.asm



