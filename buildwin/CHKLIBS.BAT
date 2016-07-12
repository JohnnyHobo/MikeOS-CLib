@Echo Off
Rem Checks if all the libraries exist in the 'lib' folder.

Rem This script is used to support the build script but can run independently
Rem by running it in the 'buildwin' folder.

Rem The script will check if the file exist for each library on the list and
Rem display a message on the screen with the file's status.

Rem The script will stop if any library file is not found.
Rem If all the library are found the variable 'HasLibs' will be defined.

Rem At the moment it needs to be update whenever a new library is added,
Rem it would be better to have some central file listing the libraries.

Set Libs=lib\libmikeos.a lib\libmemory.a lib\libc.a lib\libtextio.a lib\crt0.o
Set HasLibs=
Set FinalPause=

For %%* in (.) Do Set  CURRDIR=%%~nx*
If %CURRDIR%==buildwin (
	cd ..
	Set FinalPause=Yes
)

For %%G In (%Libs%) Do (
	Set <NUL /p=Looking for %%G...
	If Not Exist %%G (
		Echo Not Found^^!
		GoTo Finished
	) Else (
		Echo Okay.
	)
)

Echo All libraries were found.
Set HasLibs=Yes

:Finished
If Defined FinalPause (Pause)