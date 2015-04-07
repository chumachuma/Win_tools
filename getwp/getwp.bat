@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION
:START
SET SCRIPT_FOLDER=%~dps0
SET GETWP_TXT=%SCRIPT_FOLDER%getwp.txt
SET GETWP_COMMENT=
:HELP_OPTION
IF %1'==/?' (
	CALL :HELP
	GOTO :END
)
:WRITE_OPTION
IF %1'==/w' (
	CALL :WRITE_KEY_VALUE %2 %3
	GOTO :END
)
:DEFAULTS
IF [%1]==[] (
	CALL :HELP
	GOTO :END
) ELSE (
	SET KEY_WORD=%1
)
IF [%2]==[] (
	SET COMMAND=ECHO
) ELSE (
	SET COMMAND=ECHO
	IF "%2" NEQ "/a" IF "%2" NEQ "/b" IF "%2" NEQ "/c" (
		SET COMMAND=%2
	)
)
SET APPEND=\
SET BACK_COMMAND=

:PARSE_OPTIONS
FOR /F "tokens=1,2,3,4,5 delims=/" %%a IN ("%*") DO (
	SET OPTION_LINE=%%a
		CALL :EVALUATE_OPTIONS
	SET OPTION_LINE=%%b
		CALL :EVALUATE_OPTIONS
	SET OPTION_LINE=%%c
		CALL :EVALUATE_OPTIONS
	SET OPTION_LINE=%%d
		CALL :EVALUATE_OPTIONS
	SET OPTION_LINE=%%e
		CALL :EVALUATE_OPTIONS
)
GOTO MAIN

REM ####################################################################
:EVALUATE_OPTIONS
FOR %%G IN ( !OPTION_LINE! ) DO (
	IF %%G == a (
		set APPEND=!OPTION_LINE:~2!
	)
	IF %%G == b (
		set BACK_COMMAND=!OPTION_LINE:~2!
	)
	IF %%G == c (
		set COMMAND=!OPTION_LINE:~2!
	)
	IF %%G == k (
		set KEY_WORD=!OPTION_LINE:~2!
	)
)
EXIT /B 0

:HELP
ECHO Run commands with a given preset parameter shortcut.
ECHO To display this screen type: getwp /?
ECHO.
ECHO getwp keyword [/a: ] [/b: ] [/c: ]
ECHO getwp keyword command
ECHO.
ECHO /a     Appends character string at the end of the keyword
ECHO /b     Adds extra options at the end of the command
ECHO /c     Specify commands to be run
ECHO /k     Specify keyword
ECHO.
ECHO /w     Adds keyword to be used in future /w KEY "value". Use # to comment line.
ECHO /.?    Access this window
ECHO.
FOR /F "tokens=1" %%a IN (%GETWP_TXT%) DO (
	SET GETWP_COMMENT=%%a
	SET GETWP_COMMENT=!GETWP_COMMENT:~0,1!
	IF !GETWP_COMMENT! == # (
		ECHO %%a
	) ELSE (
		ECHO     %%a
	)
)
EXIT /B 0

:WRITE_KEY_VALUE
ECHO %1	%2 >> %GETWP_TXT%
EXIT /B 0
REM ####################################################################

:MAIN
SET getwp_PAIR_SWITCH=0
SET getwp_CHOICE_SWITCH=0
FOR /F "usebackq delims=" %%a IN (%GETWP_TXT%) DO (
	SET GETWP_COMMENT=%%a
	SET GETWP_COMMENT=!GETWP_COMMENT:~0,1!
	IF NOT !GETWP_COMMENT! == # (
		FOR %%b IN (%%a) DO (
			IF !getwp_PAIR_SWITCH! == 0 (
				SET getwp_PAIR_SWITCH=1
				IF /I %%b == %KEY_WORD% (
					SET getwp_CHOICE_SWITCH=1
				)
			) ELSE (
				SET getwp_PAIR_SWITCH=0
				IF !getwp_CHOICE_SWITCH! == 1 (
					REM Command execution
					%COMMAND% "%%~b%APPEND%" %BACK_COMMAND%
					REM Workaround for CD
					GOTO END
				)
			)
		)
	)
)
ECHO Keyword %KEY_WORD% doesn't exists!

:END
SET GETWP_COMMENT=
SET getwp_PAIR_SWITCH=
SET getwp_CHOICE_SWITCH=
SET SCRIPT_FOLDER=
SET GETWP_TXT=
SET KEY_WORD=
SET COMMAND=
SET APPEND=
SET BACK_COMMAND=
pushd .
ENDLOCAL
popd