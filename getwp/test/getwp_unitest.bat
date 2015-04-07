@cls
@PROMPT $G$G 
@ECHO 	=== HELP ===
	REM call getwp.bat /?
	@ECHO Problems with call?
@ECHO.	
@ECHO 	=== NO PARAMETERS ===
	call getwp.bat
@ECHO.
@ECHO 	=== DEFAULT RUN ===
	call getwp.bat HERE
@ECHO.
@ECHO 	=== FAST RUN ===
	call getwp.bat HERE echo
@ECHO.
@ECHO 	=== COMMAND RUN ===
	call getwp HERE /a \Something_behind /b "even further" /c echo
	call getwp HERE /c echo a /a "\Something_behind quotes" outside /b even further
	call getwp HERE /c echo a /a "\Something_behind quotes" outside /b even further /k ORIOL
@ECHO.
@ECHO 	=== REPLACE RUN ===
	call getwp.bat HERE dir
	call getwp.bat HERE dir /c echo
@ECHO.
@ECHO 	=== CD ===
	call getwp HERE cd
	REM WHY does it goes to System32? -> cd?
	echo %cd%
@ECHO.
@ECHO 	=== BAD CASES ===
	call getwp.bat "doesn't exists"
	call getwp.bat HERE BAD_COMMAND
@ECHO.
@ECHO 	=== END ===
@PROMPT $P$G 
REM pause
REM cd .. REM this works...
@cd D:\Desktop\Desktop_Temp\Programacio\Win_tools\getwp\test