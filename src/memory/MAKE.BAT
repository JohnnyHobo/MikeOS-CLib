Call MAKEALL
Call ECHOCMD "smlrcc -flat16 -c -o libmemory.a %OBJECTS%"
Call ECHOCMD "Copy /Y /V libmemory.a %LibDir%\libmemory.a"
