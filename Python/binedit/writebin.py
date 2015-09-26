from sys import argv, exit
from os import stat
import getopt
from binedit import writebin

class Main:
	def __init__ (self):
		self.filename = None
		self.data = None
		self.inFile = None
	
	def getDataFromFile (self):
		with open (self.inFile, 'r') as File:
			self.data = File.read()
	
	def  parseArguments (self):
		
		try:
			self.filename = argv[1]
		except:
			pass
		
		try: 
			options, args = getopt.getopt(argv[1:],'f:d:i:', ["file=", "data=", "inFile="])
		except getopt.GetoptError as err:
			print (str(err)) # will print something like "option -a not recognized"
			#getopt.usage()
			exit(2)
		for opt, arg in options:
			if opt in ('', '-f', '--file'):
				self.filename = arg
			if opt in ('-d', '--data'):
				self.data = arg
			if opt in ('-i', '--inFile'):
				self.inFile = arg
		if not self.filename and not(self.data or self.inFile): #TODO improve console input
			#getopt.usage()
			exit(2)
			
		if self.inFile:
			self.getDataFromFile()
			
	def run (self):
		writebin(self.filename, self.data)
	
	def __call__ (self):
		self.parseArguments()
		self.run()
		
			
if __name__ == "__main__":
	Main()()