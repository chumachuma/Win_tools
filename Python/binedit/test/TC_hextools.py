import testLib.TestCase

import hextools

class TC_hextools (testLib.TestCase.TestCase):
    def __init__ (self):
        testLib.TestCase.TestCase.__init__(self)
    
    def preprocessing (self):
        self.TITLE("mini API hextools")
        self.DESCRIPTION("Hexadecimals functions helper")
        
        self.appendFunctionToTest(hextools.strHex)
        self.appendFunctionToTest(hextools.hex2int)
        
        self.log.logFilename = "TC_hextools.log"
        self.log.clearFile()
        self.log.outputModes["WRITE"] = True
        self.log.setMyLog();
        
    def testprocessing (self):
        
        self.setFunction("strHex")
        
        self.COMMENT("Generic number is set correctly")
        self.assertTest(
            args = [0x11],
            expected = '11')
    
        self.COMMENT("Number is converted from decimal correctly")
        self.assertTest(
            args = [35],
            expected = '23')
        
        self.COMMENT("Hex is filled to two digits")
        self.assertTest(
            args = [0x01],
            expected = '01')
        
        self.COMMENT("Hex letters are upper")
        self.assertTest(
            args = [0x0A],
            expected = '0A')
        
        self.COMMENT("Check Boundaries 00 & FF")
        self.assertTest(
            args = [0x00],
            expected = '00')
        
        self.assertTest(
            args = [0xFF],
            expected = 'FF')
        
        self.COMMENT("Bad cases")
        self.assertTest(
            args = [0xFF+1],
            expected = "BadCase")
        
        self.setFunction("hex2int")
        
        self.COMMENT("Generic hex are set correctly")
        self.assertTest(
            args = ['01'],
            expected = 1)
        
        self.assertTest(
            args = ['FF'],
            expected = 255)
        
        self.assertTest(
            args = ['a2'],
            expected = 162)
        
        self.COMMENT("Check Boundaries 00 & FF")
        self.assertTest(
            args = ['00'],
            expected = 0)
        
        self.assertTest(
            args = ['FF'],
            expected = 0xFF)
        
        self.COMMENT("Bad cases")
        self.assertTest(
            args = ['ff1'],
            expected = "BadCase")
        
        self.COMMENT("Bad cases: not hex number")
        self.assertTest(
            args = ['xx'],
            expected = "BadCase")
if __name__ == "__main__":
    TC_hextools().run()