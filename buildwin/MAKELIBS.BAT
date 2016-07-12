@Echo Off
Rem Rebuilds the C library files in the 'lib' directory.

Rem This script enters each source directory for the C library and runs the
Rem 'MAKE.BAT' script responsible for building it and copying output files to
Rem the lib directory.


Set "LIBDIRS=mikeos memory libc textio common"
Set FinalPause=

Echo %LIBDIRS%
For %%* in (.) Do Set  CURRDIR=%%~nx*
If %CURRDIR%==buildwin (
	cd ..
	Set FinalPause=Yes
)

If Not Defined FromBuild (
	Set ScriptDir=buildwin
	Call buildwin\FINDUTIL.BAT
	Call buildwin\UTILPATH.BAT
)

For %%d in (%LIBDIRS%) Do (
	Echo Compiling from %%d directory.
	cd src\%%d
	Call make.bat
	cd ..\..
)

If Defined FinalPause (Pause)