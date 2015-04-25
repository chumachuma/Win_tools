;Version 0.1
;C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup

#SingleInstance

;MOUSE
MouseSpeed := 0.5
MouseStep := 50
DeltaX := 0
DeltaY := 0

CapsLock & 1:: MouseSpeed = 0.1
CapsLock & 2:: MouseSpeed = 0.2
CapsLock & 3:: MouseSpeed = 0.5
CapsLock & 4:: MouseSpeed = 1.0
CapsLock & 5:: MouseSpeed = 2.0

CapsLock & e:: Send {LButton}
CapsLock & r:: Send {RButton}
CapsLock & f:: Send {WheelUp}
CapsLock & c:: Send {WheelDown}

; CapsLock & w::
	; SetMouseDelay, -1
	; MouseMove, 0, -MouseStep*MouseSpeed, 0, R
	; Gosub, MOUSE_DIAG
	; return
; CapsLock & a::
	; SetMouseDelay, -1
	; MouseMove, -MouseStep*MouseSpeed, 0, 0, R
	; return
; CapsLock & s::
	; SetMouseDelay, -1
	; MouseMove, 0, MouseStep*MouseSpeed, 0, R
	; return
; CapsLock & d::
	; SetMouseDelay, -1
	; MouseMove, MouseStep*MouseSpeed, 0, 0, R
	; return
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
Send {CapsLock}