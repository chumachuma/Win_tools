byteSize = 0x08

def strHex (bn):
	if bn<=0xFF:
		return hex(bn)[2:].zfill(2).upper()
	raise TypeError ("size of %s greater than byte" % type(bn).__name__)
		
def hex2int (hx):
	if len(hx)<3:
		return int(hx, 16)
	raise TypeError ("string type longer than hex byte")