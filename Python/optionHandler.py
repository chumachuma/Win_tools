#!/usr/bin/env python3

__version__ = "0.6"

import getopt
import logging
from sys import exit

#TODO this should be inherited
class OptLogger:
  logOptions = {"NONE": logging.WARNING,
                "VERBOSE": logging.INFO,
                "DEBUG": logging.DEBUG,
                "FILE": None}
  logFormat = '%(levelname)s [%(asctime)s]: %(message)s'
  logDateFormat = '%I:%M:%S %d/%m/%Y'
  def __init__(self):
    self.logger = logging.getLogger("Logger")
    self.logger.setLevel(logging.WARNING)
    self.consoleHndl = logging.StreamHandler()
    self.consoleHndl.setLevel(logging.DEBUG)
    self.consoleHndl.setFormatter(logging.Formatter(self.logFormat, self.logDateFormat))
    self.logger.addHandler(self.consoleHndl)
    self.critical = self.logger.critical
    self.error = self.logger.error
    self.warning = self.logger.warning
    self.info = self.logger.info
    self.debug = self.logger.debug
    self.criticalIf = lambda x, y: self.logIf(x, logging.CRITICAL, y)
    self.errorIf = lambda x, y: self.logIf(x, logging.ERROR, y)
    self.warningIf = lambda x, y: self.logIf(x, logging.WARNING, y)
    self.infoIf = lambda x, y: self.logIf(x, logging.INFO, y)
    self.debugIf = lambda x, y: self.logIf(x, logging.DEBUG, y)
    self.loggerFunc = {logging.CRITICAL: self.critical, logging.ERROR: self.error,
                       logging.WARNING: self.warning, logging.INFO: self.info,
                       logging.DEBUG: self.debug}

  def setLogLevel(self, level):
    level = level.upper()
    if level not in self.logOptions:
      self.logger.warning("setLogLevel: [%s] invalid logging option [NONE, VERBOSE, DEBUG]", level)
    else:
      self.logger.setLevel(self.logOptions[level])

  def logIf(self, condition, level, msg):
    if condition:
      logger = self.getLogger(level)
      logger(msg)

  def getLogger(self, level):
    if level in self.loggerFunc:
      return self.loggerFunc[level]
    else:
      self.logger.error("getLogger: Logger level does not exist")
      return logging.warning


class Option:
  """Struct to encapsulate Option parameters"""
  def __init__(self, shortOpt, longOpt, param="", description="", function=0, default="", hidden=False):
    self.short = shortOpt
    if param: self.short+=":"
    self.long = longOpt
    if param: self.long+="="
    self.param = param
    self.default = default
    self.desc = description
    self.function = function
    self.input = ("-"+shortOpt, "--"+longOpt)
    self.hidden = hidden


class OptionHandler:
  """Creates a UNIX text based program
  program = OptionHandler(<Description_of_program>)
  program.setDefaultFunction()
  program.register()
  program.getOpt(sys.argv[1:])
  program.run()
  For debugging use hidden option -L --loging [LEVEL: NONE, VERBOSE, DEBUG]"""
  def __init__(self, description=""):
    self.logger = OptLogger()
    self.keyList = [] #Sorted list
    self.optMap = {}
    self.defaultFunction = 0
    self.opts = []
    self.args = []
    self.description = description
    self.__version__ = "Python 3.x: Option Handler %s: " % __version__
    self.register("?", "", "", "", lambda: print(self._help()))
    self.register("h", "help", "", "Show this message", lambda: [print(self._help()), exit(0)])
    self.register("v", "version", "", "Print program version", lambda: print(self.__version__))
    self.register("L", "logging", "LEVEL", "[NONE, VERBOSE, DEBUG]", self.logger.setLogLevel, hidden=True)    

  def register(self, shortOpt, longOpt, param="", description="", function=0, default="", hidden=False):
    """Register option with or without parameters
    shortOpt: abbreviated form of the option
    logOpt: option to be specified
    param: parameter that the option supports, use "" if no parameter are supported
    description: small description to be shown in help message
    function: function to be run when the option is specified
    default: default parameter if non supplied and expecting param
    hidden: true/false to hide description from help message"""
    self.keyList.append(shortOpt)
    self.logger.warningIf(shortOpt in self.optMap, "register: overriding option [%s]" % shortOpt)
    self.optMap[shortOpt] = Option(shortOpt, longOpt, param, description, function, default, hidden)
    self.logger.info("register: [%s, %s(%s=%s)] %s", shortOpt, longOpt, param, default, description)

  def setDefaultFunction(self, description="", function=0, param="", default=""):
    """Sets parameters to be run when no option is supplied or additional parameters at the end
    If the default function is not set, trying to use it will prompt the help message
    description: small description to be shown in help message
    function: function to be run
    param: parameter that the option supports, use "" if no parameter are supported
    default: default parameter if non supplied and expecting param"""
    self.defaultFunction = Option("", "", param, description, function, default)

  def getOpt(self, args):
    """Set options and arguments, usually sys.argv[1:]"""
    try:
      self.opts, self.args = getopt.getopt(args, self._getShortOpt(), self._getLongOpt())
    except Exception as e:
      print(str(e))
      print(self._help())

  def run(self):
    """Run program once the input has been set"""
    for o, a in self.opts:
      for key in self.keyList:
        if o in self.optMap[key].input:
          if self.optMap[key].param:
            if a:
              self.optMap[key].function(a)
            else:
              self.optMap[key].function(self.optMap[key].default)
          else:
            self.optMap[key].function()
          self.logger.info("run: [%s, %a]", o, a)
          break
    if self.defaultFunction:
      if self.defaultFunction.param:
        if self.args and self.args[0]:
          self.logger.info("run: [%s]", self.args)
          return self.defaultFunction.function(*self.args)
        elif self.defaultFunction.default:
          self.logger.info("run: [%s]", self.defaultFunction.default)
          return self.defaultFunction.function(self.defaultFunction.default)
        else:
          print(self._help())
      else:
        return self.defaultFunction.function()

  def _help(self):
    helpTemplateS ="  -%s   %-25s%s\n"
    helpTemplateL ="  -%s --%-25s%s\n"
    helpMsg = self.description + '\n'
    if self.defaultFunction:
      helpMsg += self.defaultFunction.desc + " [%s]"%self.defaultFunction.param + '\n'
    for key in self.keyList:
      if self.optMap[key].hidden:
        continue
      if self.optMap[key].long:
        helpMsg += helpTemplateL % (key, self.optMap[key].long + self.optMap[key].param, self.optMap[key].desc)
      else:
        helpMsg += helpTemplateS % (key, self.optMap[key].long + self.optMap[key].param, self.optMap[key].desc)
    return helpMsg

  def setInfo(self, description):
    """Set brief description to be shown in help message"""
    self.description = description

  def setVersion(self, version):
    """Set version information"""
    self.__version__ += version

  def _getShortOpt(self):
    shortOptions = ""
    for key in self.keyList:
      shortOptions+=self.optMap[key].short
    return shortOptions

  def _getLongOpt(self):
    longOptions = []
    for key in self.keyList:
      longOptions.append(self.optMap[key].long)
    return longOptions
