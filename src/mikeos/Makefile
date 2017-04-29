OBJECTS = string.o screen.o disk.o math.o misc.o ports.o basic.o keyboard.o
#OBJECTS += ../common/asm/crt0.o

all: $(OBJECTS)
	smlrcc -flat32 -c -o libmikeos.a $(OBJECTS)
	cp libmikeos.a ../../lib/libmikeos.a
	
%.o : %.c;
	smlrcc -unreal -I../../include -c $*.c -o $@ 
	
%.o : %.asm;
	#nasm -f elf32 -i../../include -o $@ $*.asm
	smlrcc -unreal -I../../include -c $*.asm -o $@




