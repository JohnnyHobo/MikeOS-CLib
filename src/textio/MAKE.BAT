Call MAKEALL
Call ECHOCMD "smlrcc -flat16 -c -o libtextio.a %OBJECTS%"
Call ECHOCMD "Copy /Y /V libtextio.a %LibDir%\libtextio.a"
