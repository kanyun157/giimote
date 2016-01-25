# Introduction #

When calling GiiMote functions it is important to understand the calling order of each function.


# Details #

When you call a GiiMote function from Game Maker the call results in the following order of operations:
  1. The Game Maker runner interprets your code containing the call to a GiiMote function.
  1. Control passes to the function which is interpreted and either returns some data or calls GiiMote (possibly passing it one or more arguments).
  1. The GiiMote DLL may perform some processing. Then it either returns or calls a function in WiimoteLib.dll.
  1. WiimoteLib gets data from its internal representation of the Wii Remote, possibly processes it, and returns.
  1. The sequence returns backwards until it reaches GM where the code continues.