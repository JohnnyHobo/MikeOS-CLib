LIBOBJ = lib/libc.a lib/libmikeos.a lib/libmemory.a lib/libtextio.a
MOSAPI = string.o screen.o disk.o math.o misc.o ports.o basic.o
SRCDIRS = mikeos memory libc textio
OBJECTS = prog.bin


all: $(LIBOBJ) $(OBJECTS)
	
.PHONY: libs
libs: $(LIBOBJ)

lib/libc.a:
	$(MAKE) -C src/libc all
	cp src/libc/libc.a lib/libc.a
	
lib/libmikeos.a:
	$(MAKE) -C src/mikeos all
	cp src/mikeos/libmikeos.a lib/libmikeos.a
	
lib/libmemory.a:
	$(MAKE) -C src/memory all
	cp src/memory/libmemory.a lib/libmemory.a
	
lib/libtextio.a:
	$(MAKE) -C src/textio all
	cp src/textio/libtextio.a lib/libtextio.a

%.bin : %.c;
	smlrcc -entry __start -flat16 -origin 32768 -SIinclude -o $@ $*.c $(LIBOBJ)
	
clean:
	-rm -f lib/*.a
	for dir in $(SRCDIRS); do \
		rm -f src/$$dir/*.o; \
		rm -f src/$$dir/*~; \
		rm -f src/$$dir/*.asm; \
		rm -f src/$$dir/asm/*.o; \
		rm -f src/$$dir/asm/*~; \
	done

