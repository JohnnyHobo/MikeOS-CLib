OBJECTS = backend.o char.o core.o cursor.o internal.o mode.o page.o print.o
OBJECTS += shapes.o ../common/minmax.o

all: $(OBJECTS)
	smlrcc -flat32 -c -o libtextio.a $(OBJECTS)
	cp libtextio.a ../../lib/libtextio.a
	
%.o : %.c;
	smlrcc -unreal -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	nasm -f elf32 -i../../include -o $@ $*.asm



