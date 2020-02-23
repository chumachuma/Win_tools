#!/usr/bin/python3

__version__ = "0.0"

import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
import xml.etree.ElementTree as xml
import re

###############################################################################
from functools import wraps # This convenience func preserves name and docstring

def addMethod(cls):
  def decorator(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
      return func(*args, **kwargs)
    setattr(cls, func.__name__, wrapper)
    return func
  return decorator
###############################################################################

@addMethod(tk.Frame)
def __getitem__(cls, key):
  """Allow quick access to elements in Frame"""
  return cls.children[key]


class GUIDock(tk.Tk):
  def __init__(self, xmlFile, *args, **kwargs):
    super().__init__(*args, **kwargs)
    self.xmlFile = xmlFile
    self.style = ttk.Style()

  def run(self):
    self.loadTree(self, xml.parse(self.xmlFile).getroot())
    self.mainloop()

  def loadTree(self, parentGUI, node):
    """Recursively load specified widgets from elementTree"""
    if node.tag == "Window":
      widget = parentGUI
    else:
      argMaster = parentGUI
      attrMaster = tk
      if self.hasattr(parentGUI, node.tag):
        attrMaster = parentGUI
        argMaster = None
      elif hasattr(ttk, node.tag):
        attrMaster = ttk
      arguments = self.parseArgs(argMaster, node.attrib)
      widgetFactory = self.getattr(attrMaster, node.tag)
      widget = widgetFactory(**arguments)
    for childNode in node:
      childWidget = self.loadTree(widget, childNode)
      if childWidget and not isinstance(childWidget, tk.Menu) and \
        not self.isPacked(childWidget): #Checks for default pack
        childWidget.pack()
    return widget

  def parseArgs(self, master, arguments):
    """Set parent of widget as an argument
    command arguments are evaluated
    values with the form @.<widget_path> returns the widget"""
    newArgs = dict(arguments)
    if master:
      newArgs["master"] = master
    if "command" in newArgs:
      newArgs["command"] = eval(newArgs["command"])
    widgetPath = re.compile("^@\.(.*)")
    for key, value in newArgs.items():
      if isinstance(value, str):
        path = widgetPath.match(value)
        if path:
          newArgs[key] = self.getWidget(path.group(1))
    return newArgs

  def isPacked(self, widget):
    """Test wether a widget has any kind of geometry packing"""
    packed = widget.grid_info() or widget.place_info()
    try: #By default pack is not defined contrary to grid or place
      packed |= widget.pack_info().empty()
    except:
      pass
    return packed

  def getWidget(self, path, master=None):
    """Return widget specfied by its branch path separated by '.'"""
    if not master:
      master = self
    vPath = path.split('.') if isinstance(path, str) else path
    if len(vPath) == 1:
      return master.children[vPath[0]]
    return self.getWidget(vPath[1:], master.children[vPath[0]])

  def hasattr(self, master, attr):
    """Recursive hasattr"""
    vAttr = attr.split('.') if isinstance(attr, str) else attr
    attrValid = hasattr(master, vAttr[0])
    if not attrValid:
      return attrValid
    elif len(vAttr) == 1:
      return attrValid
    return self.hasattr(getattr(master, vAttr[0]), vAttr[1:])

  def getattr(self, master, attr):
    """Recursive getattr"""
    vAttr = attr.split('.') if isinstance(attr, str) else attr
    slave = getattr(master, vAttr[0])
    if len(vAttr) == 1:
      return slave
    return self.getattr(slave, vAttr[1:])


if __name__ == "__main__":
  import sys

  window = GUIDock(*sys.argv[1:])

  def b1click():
    window.getWidget("frame0.label0").configure(text="clicked1")

  def b2click():
    window.getWidget("frame0.frame1.label1").configure(text="clicked2")

  def saveFile():
    fname =  filedialog.asksaveasfilename(initialdir = "./", title = "Select file",filetypes = (("all files","*.*"),))

  def openFile():
    fname =  filedialog.askopenfilename(initialdir = "./", title = "Select file",filetypes = (("all files","*.*"),))
    window.getWidget("frame0.frame1.label1").configure(text=fname)

  window.run()
