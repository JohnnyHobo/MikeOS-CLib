@Echo Off
Rem Builds all source files listed in FILES.TXT into object files.

Rem This script should be run in the directory where the source files are
Rem located, as is the file 'FILES.TXT'. 

Rem FILES.TXT contains a list of source files relative to the current
Rem directory with one file per line. C and Assembly files will be built
Rem into object files with the same basename (e.g. var/foo.c -> var/foo.o).
Rem A forward slash is used as the path seperator. 

Set OBJECTS=
For /F %%F In (FILES.TXT) Do Call :Make %%F
GoTo :MakeEnd

:Make
	Call MAKEOBJ %1
	
	If ."%OBJECTS%"==. (
		Set "OBJECTS=%OBJFILE%"
	) Else (
		Set "OBJECTS=%OBJECTS% %OBJFILE%"
	)

	GoTo :eof
	
:MakeEnd