;C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup
;WIN+T	  	-> Open cmd in current dir
;CapsLock	-> WASD
	
MouseSpeed := 0
MouseStep := 150
CapsLock & w:: MouseMove,  00, -MouseStep, MouseSpeed, R
CapsLock & a:: MouseMove, -MouseStep,  00, MouseSpeed, R
CapsLock & s:: MouseMove,  00,  MouseStep, MouseSpeed, R
CapsLock & d:: MouseMove,  MouseStep,  00, MouseSpeed, R
CapsLock & e:: Send {LButton}
CapsLock & r:: Send {RButton}
CapsLock & f:: Send {WheelUp}
CapsLock & c:: Send {WheelDown}

CapsLock & i:: Send {Up}
CapsLock & j:: Send {Left}
CapsLock & k:: Send {Down}
CapsLock & l:: Send {Right}

CapsLock & 1:: MouseStep := 25
CapsLock & 2:: MouseStep := 75
CapsLock & 3:: MouseStep := 150
	
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
