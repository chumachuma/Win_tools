import winsound
import os.path # check existence of file
from os import _exit as os_exit
import threading
from time import sleep
from datetime import datetime
import msvcrt # detects key events
import sys # for sys.argv

MUSIC_FILE = os.path.dirname(__file__) + "\\07-Rain.wav" 
PRESS_SPACE = "\n\t\t================================\n\t\t#    PRESS  SPACE  >>  EXIT    #\n\t\t================================\n"
ALARM_STARTED = "\t\tRINGGG !!!"
ALARM_SET = "\nSet alarm for: %dh and %dm\n"
HELP = """
		ALARM
	Sets an alarm (build version for python 3.3)


  -h: help 			-Displays this help screen

  -f time[h/m/s]: forward		-Set alarm after specified time

  -l hh:mm: limit			-Set alarm at time


	Usage examples:

  alarm 5				-Alarm set to 5 minutes

  alarm -f 1h3m5s			-Alarm set to 1 hour 3 minutes 5 seconds

  alarm -l 15:30			-Alarm set to 15:30

"""
FPS = 15
MINUTE2SECONDS = 60
HOUR2MINUTE = 60

class KeyEventThread (threading.Thread):
	def run (self):
		fps = FPS
		print(PRESS_SPACE)
		while True:
			sleep(1./fps)
			if msvcrt.kbhit() and msvcrt.getch()==b' ':
				os_exit(1)

class MissingFile(Exception):
	def __init__(self, value):
		self.value = value
	def __str__(self):
		return repr(self.value)

def play(file):
	winsound.PlaySound(file, winsound.SND_FILENAME)

def fileExists (file):
	if (os.path.isfile(file)):
		return True
	else:
		raise MissingFile(file)
		
class Alarm:
	"""Alarm
		Terminal alarm with two modes:
			· forward: -f time[s, m, h]
			· limit: -l hh:mm
	"""
	def __init__ (self, tm, mode="-f", file=MUSIC_FILE):
		self.mode = mode
		if fileExists(file): self.file = file
		self.time = self.time_calc(tm)
		
	def time_calc(self, tm):
		if self.mode == "-f":
			if type(tm) == int:
				tm = int(tm)*MINUTE2SECONDS
			elif type(tm) == str:
				if tm.isdigit():
					tm = int(tm)*MINUTE2SECONDS
					print (tm)
				else:
					print("NOT YET") #not yet					
					print ("Invalid input time: " + tm + 
				"\n for option" + self.mode)
		elif self.mode == "-l":
			atm = [int(x) for x in tm.split(":")]
			if atm.__len__()==2 and atm[0]<24 and atm[1]<60:
				lapse_h = atm[0] - datetime.now().hour
				if atm[1] >= datetime.now().minute:
					lapse_m = atm[1] - datetime.now().minute  
				else:
					lapse_m = 60 + atm[1] - datetime.now().minute
					lapse_h -= 1
				if lapse_h < 0:
					lapse_h += 24
				tm = ((lapse_h*HOUR2MINUTE)+lapse_m)*MINUTE2SECONDS-datetime.now().second
				print (ALARM_SET % (lapse_h, lapse_m))
			else:
				print ("Invalid input time: " + tm + 
				"\n for option" + self.mode)
		elif self.mode == "-h":
			pass
		else:
			print ("Invalid option: " + self.mode)
		return tm
		
	def alarm (self):
		if self.mode == "-f" or self.mode == "-l":
			KeyEventThread().start()
			sleep(self.time)
			print(ALARM_STARTED)
			play(self.file)
			os_exit(1)
		else:
			print (HELP)
			
			
if __name__ == "__main__":
	if sys.argv.__len__() == 1:
		Alarm(1, "-h").alarm()
	elif sys.argv.__len__() == 2:
		Alarm(sys.argv[1], "-f").alarm()
	else:
		Alarm(sys.argv[2], sys.argv[1]).alarm()