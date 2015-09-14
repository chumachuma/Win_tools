import ctypes

class getitemMetaClass (type):
	"""When an object is indexed, the special method __getitem__ is looked for first in the object's class. A class itself is an object, and the class of a class is usually type. So to override __getitem__ for a class, you can redefine its metaclass (to make it a subclass of type)"""
	
	def __init__(self, child, bases, attr):
		self.childAttributes = attr
	
	def __getitem__ (self, key):
		if key[0] == "_": # This works in this case, not in more complex child classes
			raise KeyError( key )
		return self.childAttributes[key.upper()]
	
	def __call__ (self, key):
		return self.__getitem__ (key)

class Color ():
		
	BLACK 		= 0x00
	DARKBLUE 	= 0x01
	DARKGREEN	= 0x02
	DARKAQUA	= 0x03
	DARKRED		= 0x04
	DARKPURPLE	= 0x05
	DARKYELLOW	= 0x06
	DARKWHITE	= 0x07
	GRAY		= 0x08
	BLUE		= 0x09
	GREEN		= 0x0A
	AQUA		= 0x0B	
	RED			= 0x0C
	PURPLE		= 0x0D
	YELLOW		= 0x0E
	WHITE		= 0x0F
	
	__metaclass__ = getitemMetaClass

class callMetaClass (type):
	"""Another metaclass method that's occasionally useful to override is __call__. The reason I'm discussing it separately from __new__ and __init__ is that unlike those two that get called at class creation time, __call__ is called when the already-created class is "called" to instantiate a new object"""
	def __init__(self, child, bases, attr):
		self.printC = attr["printC"]
		
	def __call__ (self, msg, color=Color.WHITE):
		myMsg = msg.encode('UTF-8')
		self.printC ( myMsg, color )
	
class printC:
	printCDLL = ctypes.CDLL ("printC.dll")
	printC = printCDLL['printC']

	__metaclass__ = callMetaClass
	
class highlight:
	printCDLL = ctypes.CDLL ("printC.dll")
	printC = printCDLL['highlight']

	__metaclass__ = callMetaClass
	
class printCH:
	printCDLL = ctypes.CDLL ("printC.dll")
	printC = printCDLL['printCH']

	__metaclass__ = callMetaClass
	
class stdoutC:
	printCDLL = ctypes.CDLL ("printC.dll")
	printC = printCDLL['stdoutC']

	__metaclass__ = callMetaClass