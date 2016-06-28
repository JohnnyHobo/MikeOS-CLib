OBJECTS = textio.o rawtio.o ../common/minmax.o

all: $(OBJECTS)
	smlrcc -flat16 -c -o libtextio.a $(OBJECTS)
	cp libtextio.a ../../lib/libtextio.a
	
%.o : %.c;
	smlrcc -tiny -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf -i../../include -o $@ $*.asm



