#summary Information on the Wii Remote's data reporting mechanisms
#labels Type-Article

# Introduction #

The Wii Remote uses Bluetooth wireless technology to communicate with the Wii and your computer. To communicate with the host the standard HID protocol is utilized; however, the Wii Remotes HID reports do not follow the standard data types, nor do they contain any report information in the HID descriptor. Only the data report length is described.

# Details #

The Wii Remote can use a number of different data reporting modes. Each of these report types contain different data from core components on the Wii Remote and/or data from an extension controller and can be sent continuously, or only when the information on the Wii Remote is updated.
Each data reporting mode is specified by the Output Report ID which the data will be sent to. The Output Report ID can be any of the following:
  * 0x30: Core buttons
  * 0x31: Core buttons and accelerometer data
  * 0x32: Core buttons with 8 extension bytes
  * 0x33: Core buttons and accelerometer data with 12 IR bytes
  * 0x34: Core buttons with 19 extension bytes
  * 0x35: Core buttons and accelerometer data with 16 extension bytes
  * 0x36: Core buttons with 10 IR bytes and 9 extension bytes
  * 0x37: Core buttons and accelerometer data with 10 IR bytes and 6 extension bytes
  * 0x3d: 21 extension bytes
  * 0x3e, 0x3f: Interleaved core buttons and accelerometer data with 36 IR bytes (reports at half speed since two output reports are used for one set of data)