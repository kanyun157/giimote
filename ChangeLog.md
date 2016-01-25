# GiiMote Version 2.5 #
Mar 08, 2008
[Revision 75](https://code.google.com/p/giimote/source/detail?r=75)

## Revisions ##
Version 2.51: Updated new function definitions in the GEX

## Breaking Changes ##
  * wm\_set\_dead\_zone has been removed

## New Functions ##
  * wm\_set\_accel\_dead\_zone\_x
  * wm\_set\_accel\_dead\_zone\_y
  * wm\_set\_accel\_dead\_zone\_z
  * wm\_get\_accel\_dead\_zone\_x
  * wm\_get\_accel\_dead\_zone\_y
  * wm\_get\_accel\_dead\_zone\_z
  * wm\_nunchuck\_set\_accel\_dead\_zone\_x
  * wm\_nunchuck\_set\_accel\_dead\_zone\_y
  * wm\_nunchuck\_set\_accel\_dead\_zone\_z
  * wm\_nunchuck\_get\_accel\_dead\_zone\_x
  * wm\_nunchuck\_get\_accel\_dead\_zone\_y
  * wm\_nunchuck\_get\_accel\_dead\_zone\_z
  * wm\_set\_joystick\_dead\_zone
  * wm\_get\_joystick\_dead\_zone
  * wm\_set\_trigger\_dead\_zone
  * wm\_get\_trigger\_dead\_zone

## Fixes ##
  * wm\_set\_calibration functions now work properly
  * wm\_disconnect now returns -1 on error

## Other ##
  * Added XML comment headers to all functions, variables, classes and namespaces in the source
  * Created a new help file documenting the internals of the library
  * Fixed all mentions of the "Microsoft Permissive License" which does not exist (It's "Public")


# GiiMote Version 2.4 #
Jan 29, 2008
[Revision 57](https://code.google.com/p/giimote/source/detail?r=57)

## Fixes ##
  * Functions relating to joystick pressure now return the proper values

## Other ##
  * All IR sensor functions now support dots 1, 2, 3, and 4


# GiiMote Version 2.3 #
Dec 22, 2007
[Revision 49](https://code.google.com/p/giimote/source/detail?r=49)

## Breaking Changes ##
  * The joystick direction functions now return degree values like the help file says

## New Functions ##
  * wm\_nunchuck\_pressure
  * wm\_classic\_pressure

## Other ##
  * The change log now gives the SVN revision number corresponding to the GiiMote build


# GiiMote Version 2.2 #
Dec 01, 2007
[Revision 37](https://code.google.com/p/giimote/source/detail?r=37)

## Revisions ##
  * Version 2.21: An old copy of the help file that did not document the new features of version 2.2 was updated

## Breaking Changes ##
  * Several functions are now less error tolerant

## Fixes ##
  * Errors are now returned instead of thrown as exceptions
  * The wm\_connected method now detects the connection status even if the connection has been dropped
  * Fixed several small memory leaks involving Mii Data
  * wm\_classic\_direction now returns the proper error code if an invalid joystick argument is supplied
  * The joystick functions now handle improper joystick arguments correctly and return -1
  * wm\_check\_extension now returns -2 if the extension check fails

## New Functions ##
  * wm\_exists
  * wm\_get\_status
  * wm\_set\_calibration\_x0
  * wm\_set\_calibration\_xg
  * wm\_set\_calibration\_y0
  * wm\_set\_calibration\_yg
  * wm\_set\_calibration\_z0
  * wm\_set\_calibration\_zg
  * wm\_classic\_set\_calibration\_maxtrigger
  * wm\_classic\_set\_calibration\_mintrigger
  * wm\_classic\_set\_calibration\_maxx
  * wm\_classic\_set\_calibration\_minx
  * wm\_classic\_set\_calibration\_midx
  * wm\_classic\_set\_calibration\_midy
  * wm\_classic\_set\_calibration\_maxy
  * wm\_classic\_set\_calibration\_miny
  * wm\_nunchuck\_set\_calibration\_x0
  * wm\_nunchuck\_set\_calibration\_xg
  * wm\_nunchuck\_set\_calibration\_y0
  * wm\_nunchuck\_set\_calibration\_yg
  * wm\_nunchuck\_set\_calibration\_z0
  * wm\_nunchuck\_set\_calibration\_zg
  * wm\_nunchuck\_set\_calibration\_maxx
  * wm\_nunchuck\_set\_calibration\_maxy
  * wm\_nunchuck\_set\_calibration\_midx
  * wm\_nunchuck\_set\_calibration\_midy
  * wm\_nunchuck\_set\_calibration\_minx
  * wm\_nunchuck\_set\_calibration\_miny

## Other ##
  * wm\_mii\_data\_inject and wm\_mii\_data\_dump now have optional third arguments for dumping/injecting individual Mii's
  * Cleaned up the source a bit more


# GiiMote version 2.1 #
Nov 21, 2007
[Revision 35](https://code.google.com/p/giimote/source/detail?r=35)

## Fixes ##
  * Fixed a small memory leak that would never occur in practice

## New Functions ##
  * wm\_set\_leds\_int(leds)
  * wm\_mii\_get\_address(mii,block)

## Other ##
  * Cleaned up the source code


# GiiMote version 2.0 #

## Breaking Changes ##
  * wm\_connect now auto-detects the write method

## Fixes ##
  * Extensions inserted before connected are now handled properly
  * When injecting Mii's the CRC is now automatically updated on the Wii Remote
  * wm\_get\_led now returns the proper value

## New Functions ##
  * wm\_set\_write\_method
  * wm\_ir\_dot\_get\_midx
  * wm\_ir\_dot\_get\_midy
  * wm\_ir\_dot\_get\_rawmidx
  * wm\_ir\_dot\_get\_rawmidy
  * wm\_mii\_update\_crc
  * wm\_mii\_dump
  * wm\_mii\_inject
  * wm\_set\_dead\_zone

## New Constants ##
  * dz\_trigger
  * dz\_joystick
  * dz\_accel