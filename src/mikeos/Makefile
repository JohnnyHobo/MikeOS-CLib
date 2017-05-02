OBJECTS = string.o screen.o disk.o math.o misc.o ports.o basic.o keyboard.o
OBJECTS += oscall.o

all: $(OBJECTS)
	smlrcc -unreal -c -o libmikeos.a $(OBJECTS)
	cp libmikeos.a ../../lib/libmikeos.a
	
%.o : %.c;
	smlrcc -unreal -I../../include -c $*.c -o $@ 
	
%.o : asm/%.asm;
	smlrcc -unreal -I../../include -c asm/$*.asm -o $@




