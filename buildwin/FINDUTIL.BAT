@Echo Off
Rem Locates programs require by the script by searching in likely folders.

Rem The script will print a message to the console upon finding each program.
Rem If any program is not found the script will print an error and terminate.

Rem This script can be used to support the main build script when run in the
Rem library's root directory or standalone when run in the script directory.

Rem If all programs are found the 'HasPrograms' variable is defined. 

Set HasPrograms=
Set FinalPause=

If Not Defined ScriptDir (
	Set ScriptDir=buildwin
)

If Not Defined LibDir (
	Set LibDir=lib
)

For %%* in (.) Do Set  CURRDIR=%%~nx*
If %CURRDIR%==%ScriptDir% (
	Set FinalPause=Yes
	cd ..
)

Echo @echo off > %ScriptDir%\UTILPATH.BAT

Set <NUL /p=Searching for NASM...

Set NASM=Unknown
If Exist "%PROGRAMFILES%\NASM\" (Set "NASM=%PROGRAMFILES%\NASM\")
If Exist "%PROGRAMFILES(X86)%\NASM\" (Set "NASM=%PROGRAMFILES(X86)%\NASM\")
If Exist "%USERPROFILE%\AppData\Local\NASM\" (Set "NASM=%USERPROFILE%\AppData\Local\NASM\")

Echo %NASM%

If %NASM%==Unknown (
	Echo.
	Echo Could not locate NASM assembler. Tried the following directories:

	Echo "%PROGRAMFILES%\NASM\"
	Echo "%PROGRAMFILES(X86)%\NASM\"
	Echo "%USERPROFILE%\AppData\Local\NASM\"

	Echo NASM assembler can be from here: http://www.nasm.us/
	Pause
	Exit
)

Echo Set "NASM=%NASM%" >> %ScriptDir%\UTILPATH.BAT



Set <NUL /p=Searching for Smaller C...

Set SMALLERC=Unknown
If Exist "%CD%\SmallerC" (Set "SmallerC=%CD%\SmallerC\v0100\binw")
If Exist "%CD%\..\SmallerC" (Set "SmallerC=%CD%\..\SmallerC\v0100\binw")
If Exist "%CD%\..\SmallerC" (Set "SmallerC=%CD%\..\SmallerC\v0100\binw")
If Exist "%PROGRAMFILES%\SmallerC\" (Set "SmallerC=%PROGRAMFILES%\SmallerC\v0100\binw")
If Exist "%PROGRAMFILES(X86)%\SmallerC\" (Set "SmallerC=%PROGRAMFILES(X86)%\SmallerC\v0100\binw")

Echo %SmallerC%

If %SmallerC%==Unknown (
	Echo.
	Echo Could not locate Smaller C compiler. Tried the following directories:
	
	Echo "%CD%\SmallerC"
	Echo "%CD%\..\SmallerC"
	Echo "%PROGRAMFILES%\SmallerC\"
	Echo "%PROGRAMFILES(X86)%\SmallerC\"
	
	Echo The Smaller C compiler can be found here: https://github.com/alexfru/SmallerC
	Pause
	Exit
)

Echo Set "SmallerC=%SmallerC%" >> %ScriptDir%\UTILPATH.BAT

Pushd %ScriptDir%
Set ScriptDir=%cd%
Popd

Pushd %LibDir%
Set LibDir=%cd%
Popd

Echo Set "ScriptDir=%ScriptDir%" >> %ScriptDir%\UTILPATH.BAT
Echo Set "LibDir=%LibDir%" >> %ScriptDir%\UTILPATH.BAT
Echo Set "PATH=%%PATH%%;%SmallerC%;%NASM%;%ScriptDir%" >> %ScriptDir%\UTILPATH.BAT

Set HasPrograms=Yes

If Defined FinalPause (Pause)
