# Introduction #

The Wii Remote uses infrared points emitted by the poorly named "Sensor Bar" (which does no sensing) to estimate its exact orientation and offset. It tracks these points using a built in infrared camera centered on the end of the chip.

# Details #

The Wii Remote camera is a 128x96 monochrome camera with an IR-pass filter. A built in preprocessor tracks up to 4 moving points and uses 8x subpixel analysis to provide 1024x768 resolution. The Wii Remote's camera has a [focal length](http://en.wikipedia.org/wiki/Focal_length) of 1320.