Call MAKEALL
Call ECHOCMD "smlrcc -flat16 -c -o libmikeos.a %OBJECTS%"
Call ECHOCMD "Copy /Y /V libmikeos.a %LibDir%\libmikeos.a"
