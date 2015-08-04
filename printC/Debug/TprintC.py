import ctypes

# printCDLL = ctypes.WinDLL ("printC.dll")
printCDLL = ctypes.CDLL ("printC.dll")
b = ctypes.create_string_buffer(b"Hello World!")
b = ctypes.c_char_p(b'Hello World!')
printC = printCDLL['printC']
a = printC (b, 10)