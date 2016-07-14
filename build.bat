@Echo Off
Rem Main Build Script.
Rem This script will take a .c file and convert it into a .bin file of the same name.
Rem Run this as "build.bat (filename)" in the current directory to build a specific file.
Rem Use the name of the source or output binary file (i.e. prog.c or prog.bin)
Rem Or just run it without parameters and you will be prompted for a filename.

Rem There are various support scripts to deal with dependencies programs and libraries.
Rem These scripts (in the 'buildwin' directory) include:
Rem   FINDUTIL.BAT --- Generates UTILPATH.BAT
Rem   UTILPATH.BAT --- Set the search path to include build script programs.
Rem   MAKELIBS.BAT --- Builds the C libraries. Can be run outside this build script.
Rem   CHKLIBS.BAT --- Checks if the libraries exist.
Rem   MAKEALL.BAT --- Builds all source files from in FILES.TXT.
Rem   MAKEOBJ.BAT --- Builds C or Assembly source files into objects.

Rem There are also the following files included in each source directory.
Rem   MAKE.BAT --- Script to build source files in this directory.
Rem   FILES.TXT --- List of source files in this directory.

Set FromBuild=Yes
Set ScriptDir=buildwin
Set LibDir=lib

Call %ScriptDir%\FINDUTIL.BAT
Call %ScriptDir%\UTILPATH.BAT

Call CHKLIBS

If Defined HasLibs GoTo :LibsOkay

Echo Libraries are missing, attempting to rebuild libraries.
Call MAKELIBS
Call CHKLIBS
If Defined HasLibs GoTo :LibsOkay

Echo Building libraries failed.
Pause
Exit

:LibsOkay
If Not -%1-==-- (
	Set HasArg=%1
	GoTo :HasArg
)

:RetryFilename
Echo.
Echo Files in this directory:
Dir /B *.c
Echo.
Echo Files in the 'test' directory:
Dir /B test\*.c

Echo.
Echo Enter the name of the file to compile or leave the input blank to cancel.
Set INFILE=
Set /P INFILE="Filename> "
Echo.

If Not Defined INFILE (
	Echo Compiling cancelled.
	Pause
	Exit
)
	
:HasArg

Echo %INFILE% | Find ".c" > NUL

If %ERRORLEVEL% == 0 (
	GoTo :FilenameC
)

Echo %INFILE% | Find ".bin" > NUL
	
If %ERRORLEVEL% == 0 (
	GoTo :FilenameBin
) Else (
	Echo Invalid file extension.
	GoTo  :RetryFilename
)

:FilenameC
Set BINNAME=%INFILE:.c=.bin%
Set CNAME=%INFILE%
GoTo :FilenameValid

:FilenameBin
Set BINNAME=%INFILE%
Set CNAME=%INFILE:.bin=.c%
GoTo FilenameValid

:FilenameValid
If Exist %CNAME% GoTo :StartCompile
If Exist test\%CNAME% GoTo :InTestDir

Echo File %CNAME% not found in current folder or test folder.
GoTo :RetryFilename

:InTestDir
Set CNAME=test\%CNAME%
Set BINNAME=test\%BINNAME%

:StartCompile
Echo Compiling...
Echo smlrcc -entry __start -flat16 -SIinclude -o %BINNAME% %CNAME% %LIBS%
smlrcc -entry __start -flat16 -SIinclude -o %BINNAME% %CNAME% %LIBS%

Echo.

If %ErrorLevel% == 0 (
	Echo Build Complete.
) Else (
	Echo Build Failed.
)

Pause
