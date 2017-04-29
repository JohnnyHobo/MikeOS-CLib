OBJECTS = textio.o rawtio.o ../common/minmax.o

all: $(OBJECTS)
	smlrcc -flat32 -c -o libtextio.a $(OBJECTS)
	cp libtextio.a ../../lib/libtextio.a
	
%.o : %.c;
	smlrcc -unreal -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf32 -i../../include -o $@ $*.asm



