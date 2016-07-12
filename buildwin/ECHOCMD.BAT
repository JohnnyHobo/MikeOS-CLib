Echo %~1
%~1 > NUL

If Not %ERRORLEVEL% == 0 (
	Echo "Command Failed."
	Pause
	Exit
)