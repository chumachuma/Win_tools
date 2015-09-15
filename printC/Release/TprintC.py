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

stdoutC("with ", 8, 0xFF)
stdoutC("stdoutC ", 9, 0xFF)
stdoutC("you ", 10, 0xFF)
stdoutC("can ", 11, 0xFF)
stdoutC("write ", 12, 0xFF)
stdoutC("multi ", 13, 0xFF)
stdoutC("colored ", 14, 0xFF)
stdoutC("sentences\n", 15, 0xFF)

stdoutC("with ", 0x2F, 0xFF)
stdoutC("highlight\n", 0x34, 0xFF)
stdoutC("If no mask is given assume 0X0F don't know why\n", 0x76)
stdoutC("using mask FF\n", 0x2F, 0xFF)
stdoutC("using mask 0F\n", 0x2F, 0x0F)
stdoutC("using mask F0\n", 0x2F, 0xF0)

print ("mask should be 0x00 or 0x0F (change color only),\nor 0xF0 (change background only)")