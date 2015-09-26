from sys import argv, exit
from os import stat
import getopt
from binedit import readbin

class Main:
	def __init__ (self):
		self.filename = None
		self.blocksize = None
		self.lineLength = 0x10
		self.offset = 0x00
	
	def  parseArguments (self):
		
		try:
			self.filename = argv[1]
		except:
			pass
		
		try: 
			options, args = getopt.getopt(argv[1:],'f:b:l:o:', ["file=", "blocksize=", "linelengh=", "offset="])
		except getopt.GetoptError as err:
			print (str(err)) # will print something like "option -a not recognized"
			#getopt.usage()
			exit(2)
		
		for opt, arg in options:
			if opt in ('', '-f', '--file'):
				self.filename = arg
			if opt in ('-b', '--blocksize'):
				self.blocksize = int(arg)
			if opt in ('-l', '--lineLength'):
				self.lineLength = int(arg)
			if opt in ('-o', '--offset'):
				self.offset = int(arg)
		
		if not self.filename:
			#getopt.usage()
			exit(2)
				
		if not self.blocksize:
			self.blocksize = stat(self.filename).st_size

	def run (self):
		readbin(self.filename, self.blocksize, self.lineLength, self.offset)
	
	def __call__ (self):
		self.parseArguments()
		self.run()
			
			
if __name__ == "__main__":
	Main()()