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
stdoutC("sentences\n", 15)

stdoutC("with ", 0x2F)
stdoutC("highlight ", 0x34)
stdoutC("using mask \n", 0x2F, 240)
printC("Hello", Color.BLUE, 0x00) # ERROR
print ("mask should be 0x00 or 0xF0 (change color only),\nor 0x0F (change background only)")