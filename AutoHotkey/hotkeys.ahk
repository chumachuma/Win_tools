;Version 0.1
;C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup

;WIN+T	  	-> Open cmd in current dir
;CapsLock	-> WASDj

;GENERAL
CapsLock::SetCapsLockState, AlwaysOff
^CapsLock::CapsLock


;MOUSE
CapsLock & 1:: MouseStep := 25
CapsLock & 2:: MouseStep := 75
CapsLock & 3:: MouseStep := 150

MouseSpeed := 50
MouseStep := 150

CapsLock & w:: MouseMove,  00, -MouseStep, MouseSpeed, R
CapsLock & a:: MouseMove, -MouseStep,  00, MouseSpeed, R
CapsLock & s:: MouseMove,  00,  MouseStep, MouseSpeed, R
CapsLock & d:: MouseMove,  MouseStep,  00, MouseSpeed, R
CapsLock & e:: Send {LButton}
CapsLock & r:: Send {RButton}
CapsLock & f:: Send {WheelUp}
CapsLock & c:: Send {WheelDown}
;----------------------------------------------------------------------

;ARROWS
CapsLock & i::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send {Alt Down}{Up}{Alt Up}
	else if shiftState=D
		Send {Shift Down}{Up}{Shift Up}
	else if controlState=D
		Send {Control Down}{Up}{Shift Up}
	else
		Send {Up}
	return
	
CapsLock & j::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send {Alt Down}{Left}{Alt Up}
	else if shiftState=D
		Send {Shift Down}{Left}{Shift Up}
	else if controlState=D
		Send {Control Down}{Left}{Shift Up}
	else
		Send {Left}
	return
	
CapsLock & k::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send {Alt Down}{Down}{Alt Up}
	else if shiftState=D
		Send {Shift Down}{Down}{Shift Up}
	else if controlState=D
		Send {Control Down}{Down}{Shift Up}
	else
		Send {Down}
	return
	
CapsLock & l::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send {Alt Down}{Right}{Alt Up}
	else if shiftState=D
		Send {Shift Down}{Right}{Shift Up}
	else if controlState=D
		Send {Control Down}{Right}{Shift Up}
	else
		Send {Right}
	return
;----------------------------------------------------------------------
	
#IfWinActive ahk_class CabinetWClass ; for use in explorer.
#t::
	ClipSaved := ClipboardAll
	Send !d
	Send ^c
	Run, cmd /K "cd /D `"%clipboard%`""
	Clipboard := ClipSaved
	ClipSaved =
#IfWinActive
return

#IfWinNotActive ahk_class CabinetWClass ;
#t::
	Run, cmd /K "cd C:\Users\Jia-Jiunn"
#IfWinActive
return
