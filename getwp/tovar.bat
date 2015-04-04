@ECHO OFF
SET SCRIPT_FOLDER=%~dps0

%* > %SCRIPT_FOLDER%\temp\outvar
SET /p OUTVAR=< "%SCRIPT_FOLDER%\temp\outvar"
DEL %SCRIPT_FOLDER%\temp\outvar
echo OUTVAR=%OUTVAR% 