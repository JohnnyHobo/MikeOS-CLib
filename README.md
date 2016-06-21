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




