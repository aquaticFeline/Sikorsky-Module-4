<!-- :: Batch section
@echo off

:ARGS
echo.
echo.
echo.
echo ============================================
echo Update Drivers (Requires Admin Access)   [0]
echo Turn Into Arduino                        [1]
echo Turn Into Joystick                       [2]
echo Exit                                     [3]
echo ============================================
set /p id="Enter Number: "
echo ============================================
echo.
echo.
echo.

IF "%id%" == "0" (
	cd %~dp0UnoJoyWin\
	call "UnoJoyDriverInstaller.bat"
)

IF "%id%" == "1" (
	cd %~dp0UnoJoyWin\
	call "TurnIntoAnArduino.bat"
)

IF "%id%" == "2" (
	cd %~dp0UnoJoyWin\
	call "TurnIntoAJoystick.bat"
)

IF "%id%" == "3" (
	goto EXIT
)

goto ARGS
-->

:EXIT
pause