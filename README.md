### MikeOS C Library ###
A C library for MikeOS that provides C language wrappers for MikeOS functions
and *some* standard library calls.

### Requirements ###
You will need:
 * NASM Assembler - http://www.nasm.us/
 * Smaller C Compiler - https://github.com/alexfru/SmallerC
 * MikeOS 4.5 or later - http://mikeos.sourceforge.net/
 * A Windows or Linux environment for the build.

### Building C Programs ###
Place with .c file you would like to build in the library's folder.

On Linux, run `make (name).bin` to build. 
(e.g. for 'foo.c' run `make foo.bin`)

On Windows, run the batch file 'build.bat' and enter the filename when
prompted or run `build.bat (filename)` from the commandline.

A MikeOS binary file will be produced.

The binary file can be added to a MikeOS disk image by using a disk image
tool, such as WinImage on Windows or by mounting the image on Linux.

### Building Libraries ###
Precompiled libraries are provided, but you can rebuild them manually if you
have added/changed part of it.

On Linux, run `make libs` to build the libraries.

On Windows, run 'MAKELIBS.BAT' from the 'buildwin' folder.

This should produce the following library objects in the 'lib' folder:
 * *libc.a* - Provides a few standard library functions.
 * *libmemory.a* - Provides the memory manager.
 * *libmikeos.a* - Provides MikeOS API Wrappers.
 * *libtextio.a* - Text mode drawing library.
 * *crt0.o* - Program starter.
 * *crt0_s.o* - Simplified program starter for programs not using libc.

### Headers ###
See the [Functions List](functions.md) for a list of usable functions.
 * *mikeos.h* - Provides C prototypes for all the MikeOS API.
 * *textio.h* - Provides text mode drawing functions.
 * *stdlib.h* - Provides limited C Language functionality.
 * *stdio.h* - Provides limited C Language functionality.
 * *string.h* - Provides limited C Language functionality.
 * *stdbool.h* - Provides limited C Language functionality.

### Example Programs ###
Three example programs have been provided in the 'test' folder
 * *args.c* - Echos the arguments passed from the commandline.
 * *disktest.c* - Tests the disk API.
 * *echo.c* - Reports the character code and key code for each key press.
 * *prog.c* - A simple example programs using only standard library functions.
 * *prog2.c* - A keyboard and text-based graphics example.
 * *prog3.c* - Tests standard library memory and string functions.
 * *textio.c* - An example program for the TextIO library.

### FAQ ###

##### Can I use GCC to build MikeOS programs? #####
No, GCC cannot generate real mode binaries that are needed by MikeOS.
Additionally, GCC would need to be rebuilt to cross compile for another
operating system.

##### I have found bug in the build script. #####
Email me at: zerokelvinkeyboard@gmail.com

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
No, this is a limitation of the Smaller C compiler in 16-bit mode.

MikeOS function that use 32-bit integers use the 'longint' structure.

    struct longint {
	    unsigned int lower;
	    unsigned int upper;
    };

I may add a library to work with these.

##### Can I put data at a fixed address like in MikeOS Assembly? #####
No, use malloc() to allocate memory.
If you want to load a file to memory, you must use a block returned by malloc.

##### Do I need to check the return value of malloc()? #####
Yes, there is a limited amount of memory available and the memory manager will 
fail if you attempted to allocate too much memory.

