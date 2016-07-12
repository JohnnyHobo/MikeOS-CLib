Call MAKEALL
Call ECHOCMD "smlrcc -flat16 -c -o libc.a %OBJECTS%"
Call ECHOCMD "Copy /Y /V libc.a %LibDir%\libc.a"
