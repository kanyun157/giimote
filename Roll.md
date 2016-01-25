# Introduction #

Roll is one of the three Tait-Bryan rotations along with [pitch](Pitch.md) and [yaw](Yaw.md) and is defined as the rotation of a rigid body around its longitudinal (Y on the Wii Remote) axis.

# Calculation #

When the Wii Remote is at rest roll can be calculated from the force of gravity alone, but when in motion Infrared must be used as well. If infrared is not available and the Wii Remote is accelerating then roll must be approximated.

## Accelerometer ##

To calculate roll purely with data from the accelerometers the Wii Remote must be at rest. This calculation can be performed using:
```
arcsin(ax) * -1 // Multiply by -1 to make 1G a counterclockwise rotation.
```
However, as x is turned towards being parallel to the axis of gravity it will begin to lose resolution and become less accurate. For this reason this method is only truly useful between ±π/4. Also using this method will only result in values between ±π/2. Past that we must also know the quadrant that the roll is in because we will obtain the same values at 0 radians as we will at 3π/2 radians.
To solve this problem one must use two accelerometers. For this one can simply calculate the arctangent of az/ax:
```
arctan2(az, ax) - π/2; // Subtract π/2 to give it the same orientation as the method above 
```
Using this function will result in values between π/2 radians (Wii Remote lying on its left side) and -3π/2 radians (Wii Remote rotated clockwise until it is on its left side again).
One can also use all three accelerometers to find the roll of the Wii Remote in three dimensions like so:
```
arctan2(ax, sqrt( sqr(ay) + sqr(az) )) * -1
```
However, this suffers from many of the same limitations as the first method, using only one accelerometer.

## Infrared ##

To calculate roll from two infrared points we must also use the arctan function. This time however, we must take the arctangent of the slope of the line connecting the two points, that is, the arctangent of ∆y/∆x.
```
arctan2(∆y, ∆x);
```
This method will return values between ±π/2 radians with 0 corresponding to a Wii Remote lying on a flat surface with the buttons facing up or down.