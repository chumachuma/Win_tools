import hextools

class Readbin:
    def __init__ (self):
        self.line = None
    
    def outputline (self):
        str = ""
        for char in self.line:
            str += hextools.strHex(char) + " "
        print (str)
    
    def __call__ (self, filename, blocksize, lineLength, offset):
        currentSize = 0
        with open(filename, "rb") as binFile:
            binFile.seek(offset)
            while currentSize < (blocksize):
                currentSize += lineLength
                self.line = binFile.read(lineLength)
                self.outputline()
            remainingLength = blocksize % currentSize
            self.line = binFile.read(remainingLength)
            self.outputline()
            
class Writebin:
    def __init__ (self):
        self.data = None
    
    def processData (self, data):
        self.data = [hextools.hex2int(i) for i in data.replace("\n", "").split(" ")]
        
    def write (self, binFile):
        for intByte in self.data:
            binFile.write( bytes([intByte]) )
        
    def __call__ (self, filename, data):
        self.processData(data)
        with open(filename, "wb") as binFile:
            self.write(binFile)
    
readbin = Readbin()
writebin = Writebin()