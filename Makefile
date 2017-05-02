SRCDIRS = mikeos memory libc textio common
LIBOBJS = libc.a libmikeos.a libmemory.a libtextio.a crt0.o c0du.o


all: libs
	
.PHONY: libs
libs: $(addprefix lib/,$(LIBOBJ))
	for libdir in $(SRCDIRS); do \
		$(MAKE) -C src/$$libdir all; \
	done

%.bin : %.c;
	smlrcc -unreal -SIinclude -o src/common/exefile.dat $*.c $(addprefix lib/,$(LIBOBJS))
	nasm -fbin -o $@ src/common/asm/loader.asm

%.asm : %.c;
	smlrcc -unreal -SIinclude -c -S $*.c -o $@
	
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

