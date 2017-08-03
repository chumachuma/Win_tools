#!/usr/bin/env python3

__version__ = "0.2"

import getopt

class Option:
  def __init__(self, shortOpt, longOpt, param="", description="", function=0):
    self.short = shortOpt
    if param: self.short+=":"
    self.long = longOpt
    if param: self.long+="="
    self.param = param
    self.desc = description
    self.function = function
    self.input = ("-"+shortOpt, "--"+longOpt)


class OptionHandler:
 
  def __init__(self):
    self.keyList = [] #Sorted list
    self.optMap = {}
    self.defaultFunction = 0
    self.opts = []
    self.args = []
    self.__version__ = "Python 3.x: Option Handler %s: " % __version__
    self.register("h", "help", "", "Show this message", lambda: print(self.help()))
    self.register("v", "version", "", "Print program version", lambda: print(self.__version__))
  
  def register(self, shortOpt, longOpt, param="", description="", function=0):
    self.keyList.append(shortOpt)
    self.optMap[shortOpt] = Option(shortOpt, longOpt, param, description, function)

  def setDefaultFunction(self, description, function=0):
    self.defaultFunction = Option("", "", "", description, function)

  def getOpt(self, args):
    try:
      self.opts, self.args = getopt.getopt(args, self.getShortOpt(), self.getLongOpt())
    except Exception as e:
      print(str(e))
      print(self.help())

  def run(self):
    for o, a in self.opts:
      for key in self.keyList:
        if o in self.optMap[key].input:
          if self.optMap[key].param:
            self.optMap[key].function(a)
          else:
            self.optMap[key].function()
          break
    if self.args:
      if self.defaultFunction:
        self.defaultFunction.function(*self.args)
      else:
        print(self.help)

  def help(self):
    helpTemplate ="  -%s --%-25s%s\n"
    helpMsg = ""
    if self.defaultFunction:
      helpMsg += self.defaultFunction.desc + '\n'
    for key in self.keyList:
      helpMsg += helpTemplate % (key, self.optMap[key].long + self.optMap[key].param, self.optMap[key].desc)
    return helpMsg

  def setVersion(self, version):
    self.__version__ += version

  def getShortOpt(self):
    shortOptions = ""
    for key in self.keyList:
      shortOptions+=self.optMap[key].short
    return shortOptions

  def getLongOpt(self):
    longOptions = []
    for key in self.keyList:
      longOptions.append(self.optMap[key].long)
    return longOptions
