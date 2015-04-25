;Version 0.2
;C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup

#SingleInstance

;MOUSE
MouseSpeed := 0.5
MouseStep := 50
DeltaX := 0
DeltaY := 0

Hotkey, CapsLock & e, ButtonLeft
Hotkey, CapsLock & r, ButtonRight
Hotkey, CapsLock & q, ButtonMiddle
Hotkey, CapsLock & f, WheelUp
Hotkey, CapsLock & c, WheelDown

CapsLock & 1:: MouseSpeed = 0.1
CapsLock & 2:: MouseSpeed = 0.2
CapsLock & 3:: MouseSpeed = 0.5
CapsLock & 4:: MouseSpeed = 1.0
CapsLock & 5:: MouseSpeed = 2.0
CapsLock & o:: MouseSpeed *= 0.9
CapsLock & p:: MouseSpeed *= 1.1

CapsLock & w::
	DeltaY := -MouseStep*MouseSpeed
	Gosub, MOUSE_MOVE
	return
CapsLock & s::
	DeltaY := MouseStep*MouseSpeed
	Gosub, MOUSE_MOVE
	return
CapsLock & a::
	DeltaX := -MouseStep*MouseSpeed
	Gosub, MOUSE_MOVE
	return
CapsLock & d::
	DeltaX := MouseStep*MouseSpeed
	Gosub, MOUSE_MOVE
	return
;----------------------------------------------------------------------

;ARROWS
CapsLock & i::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send !{Up}
	else if shiftState=D
		Send +{Up}
	else if controlState=D
		Send ^{Up}
	else
		Send {Up}
	return
	
CapsLock & j::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send !{Left}
	else if shiftState=D
		Send +{Left}
	else if controlState=D
		Send ^{Left}
	else
		Send {Left}
	return
	
CapsLock & k::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send !{Down}
	else if shiftState=D
		Send +{Down}
	else if controlState=D
		Send ^{Down}
	else
		Send {Down}
	return
	
CapsLock & l::
	GetKeyState, altState, Alt
	GetKeyState, shiftState, Shift
	GetKeyState, controlState, Control
	if altState=D
		Send !{Right}
	else if shiftState=D
		Send +{Right}
	else if controlState=D
		Send ^{Right}
	else
		Send {Right}
	return
;----------------------------------------------------------------------
	
;TERMINAL
#IfWinActive ahk_class CabinetWClass ; for use in explorer.
#t::
	ClipSaved := ClipboardAll
	Send !d^c
	if clipboard=Computer
		Run, cmd /K "cd C:\Users\Jia-Jiunn"
	else
		Run, cmd /C "pushd `"%clipboard%`" && start cmd"
	Clipboard := ClipSaved
	ClipSaved =
#IfWinActive
return

#IfWinNotActive ahk_class CabinetWClass ;
#t::
	Run, cmd /K "cd C:\Users\Jia-Jiunn"
#IfWinActive
return

;----------------------------------------------------------------------
;GENERAL
CapsLock::SetCapsLockState, AlwaysOff
^CapsLock::CapsLock
;Send {CapsLock}

return ; end auto?
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ButtonLeft:
	SetMouseDelay, -1  ; Makes movement smoother.
	MouseClick, left,,, 1, 0, D  ; Hold down the left mouse button.
	KeyWait, e
	MouseClick, left,,, 1, 0, U  ; Release the mouse button.
	return

ButtonRight:
	SetMouseDelay, -1  ; Makes movement smoother.
	MouseClick, right,,, 1, 0, D  ; Hold down the right mouse button.
	KeyWait, r
	MouseClick, right,,, 1, 0, U  ; Release the mouse button.
	return

ButtonMiddle:
	SetMouseDelay, -1  ; Makes movement smoother.
	MouseClick, middle,,, 1, 0, D  ; Hold down the right mouse button.
	KeyWait, q
	MouseClick, middle,,, 1, 0, U  ; Release the mouse button.
	return

WheelUp:
	Send {WheelUp}
	return

WheelDown:
	Send {WheelDown}
	return
	
MOUSE_MOVE:
	GetKeyState, wState, w
	GetKeyState, aState, a
	GetKeyState, sState, s
	GetKeyState, dState, d
	if wState=D
		DeltaY := -MouseStep*MouseSpeed
	if aState=D
		DeltaX := -MouseStep*MouseSpeed
	if sState=D
		DeltaY := MouseStep*MouseSpeed
	if dState=D
		DeltaX := MouseStep*MouseSpeed
	SetMouseDelay, -1
	MouseMove, DeltaX, DeltaY, 0, R
	DeltaX := 0
	DeltaY := 0
	return