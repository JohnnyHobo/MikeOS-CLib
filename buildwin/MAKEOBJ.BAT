@Echo Off
Rem Converts the given source file into an object file.

Rem This script is given a source file relative to the current directory as a
Rem parameter and compiles it to an object file with the same basename 
Rem (e.g. var\foo.c -> var\foo.o).

Rem If forward slack is given as part of the path name it is converted to a 
Rem backslash.

Rem This script will echo the build command to the terminal for each run.

Rem If a build error occur, an error message will be written to the terminal
Rem and the script will exit. 

Rem The variable 'OBJFILE' will be set to the name of the new object file.

Set SRCFILE=%1

Call :GetNames %1
Echo smlrcc -tiny -I..\..\include -c %SRCFILE% -o %OBJFILE%
smlrcc -tiny -I..\..\include -c %SRCFILE% -o %OBJFILE%

If Not Exist %OBJFILE% (
	Echo Compilation Failed.
	Pause
	Exit
)
	
GoTo :Finished

:GetNames
	Set OBJFILE=
	Set "SRCFILE=%1"
	Set "SRCFILE=%SRCFILE:/=\%"
	
	Echo %SRCFILE% | Find ".c" > NUL
	
	If %ERRORLEVEL% == 0 (
		Set "OBJFILE=%SRCFILE:.c=.o%"
	)

	Echo %SRCFILE% | Find ".asm" > NUL
	
	If %ERRORLEVEL% == 0 (                                                                                                          
		Set "OBJFILE=%SRCFILE:.asm=.o%"
	)
	
	If .%OBJFILE%==. (
		Echo File %SRCFILE% is not a C or assembly file.
		Echo Building object file failed.
		Pause
		Exit
	)

	GoTo :eof

:Finished
