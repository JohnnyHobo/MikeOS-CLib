### MikeOS C Library ###
A C library for MikeOS that provides C language wrappers for MikeOS functions
and *some* standard library calls.

### Requirements ###
You will need:
 * NASM Assembler - http://www.nasm.us/
 * Smaller C Compiler - https://github.com/alexfru/SmallerC
 * MikeOS 4.5 or later - http://mikeos.sourceforge.net/
 * A Linux environment for the build.

### Building Libraries ###
Run `make libs` to build the libraries.

This should produce three library objects:
 * *libc.a* - Provides a few standard library functions.
 * *libmemory.a* - Provides the memory manager.
 * *libmikeos.a* - Provides MikeOS API Wrappers.

### Building C Programs ###
Place the C source file in the library's root directory and run
`make (name).bin` to build. (e.g. for 'foo.c' run `make foo.bin`).

A MikeOS binary file will be produced.

Copy the MikeOS binary to the 'programs' directory in the MikeOS directory and
run the build script appropriate for your operating system, or simple add the
binary file to the MikeOS disk image.

### Example Programs ###
Three example programs have been provided:
 * *echo.c* - Reports the character code and key code for each key press.
 * *prog.c* - An example programs using only standard library functions.
 * *prog2.c* - A keyboard and text-based graphics example.

### FAQ ###

##### Can I use GCC to build MikeOS programs? #####
No, GCC cannot generate real mode binaries that are needed by MikeOS.
Additionally, GCC would need to be rebuilt to cross compile for another
operating system.

##### What if I am not running Linux? #####
The build script should work fine on OSX but I haven't tested it.
On Windows you might want to try installing Cygwin and building with that.

##### How can I use the wrapper functions? #####
Take a look at the prototypes in the [Functions List](functions.md).

##### Which standard library functions can I use? #####
Take a look at the prototypes in the [Functions List](functions.md).

##### I'm having problems with floating point numbers. #####
There is no MikeOS support for floating point values.
I might add floating point support to the library eventually.

##### How large is an 'int' or 'unsigned int'? #####
The size of 'int' is 16-bits.
Don't forget the put 'U' on the end of unsigned constants larger than 32767.

##### Can I use a 32-bit (or larger) variable? #####
No, this is a limitation of the Smaller C compiler.

##### Can I put data at a fixed address like in MikeOS Assembly? #####
No, use malloc() to allocate memory.
If you want to load a file to memory, you must use a block returned by malloc.

##### Do I need to check the return value of malloc()? #####
Yes, there is a limited amount of memory available and the memory manager will 
fail if you attempted to allocate too much memory.

