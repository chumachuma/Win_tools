from printC import *

print ( Color.AQUA )
print ( Color["AQUA"] )
print ( Color("AQUA") )
print ( Color("aqua") )

#print ( Color["ERROR"] ) #Error case #gooD!
# print ( Color["__module__"] ) #Dangerous!: Uncontrolled access

printC("Hello", Color.BLUE)
printC("World!", Color.RED)
printC("Dark red", Color["DARKRED"])
printCH("Any Setup 0x2F", 0x2F)
highlight("Aqua highlight", Color["aqua"])
print ("check highlight limit")
print ("end anything")