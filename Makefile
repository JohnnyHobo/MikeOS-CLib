SRCDIRS = mikeos memory libc textio common
LIBOBJS = libc.a libmikeos.a libmemory.a libtextio.a crt0.o


all: libs
	
.PHONY: libs
libs: $(addprefix lib/,$(LIBOBJ))
	for libdir in $(SRCDIRS); do \
		$(MAKE) -C src/$$libdir all; \
	done

%.bin : %.c;
	smlrcc -entry __start -flat16 -origin 32768 -SIinclude -o $@ $*.c $(addprefix lib/,$(LIBOBJS))
	
clean:
	rm -f lib/*.a
	for dir in $(SRCDIRS); do \
		rm -f src/$$dir/*.o; \
		rm -f src/$$dir/*~; \
		rm -f src/$$dir/*.asm; \
		rm -f src/$$dir/asm/*.o; \
		rm -f src/$$dir/asm/*~; \
		rm -f src/$$dir/asm/*.a; \
	done

