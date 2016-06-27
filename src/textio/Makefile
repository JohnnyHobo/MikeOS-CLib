OBJECTS = textio.o

all: $(OBJECTS)
	smlrcc -flat16 -c -o libtextio.a $(OBJECTS)
	cp libtextio.a ../../lib/libtextio.a
	
%.o : %.c;
	smlrc -seg16 $*.c $*.asm
	nasm -f elf -o $@ $*.asm 
	
%.o : %.asm;
	nasm -f elf -o $@ $*.asm



