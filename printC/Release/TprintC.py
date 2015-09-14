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

stdoutC("with ", 8)
stdoutC("stdoutC ", 9)
stdoutC("you ", 10)
stdoutC("can ", 11)
stdoutC("write ", 12)
stdoutC("multi ", 13)
stdoutC("colored ", 14)
stdoutC("sentences ", 15)