# Introduction #

Pitch is one of the three Tait-Bryan rotations along with [roll](Roll.md) and [yaw](Yaw.md) and is defined as the rotation of a rigid body around its lateral, or "transverse", axis (X on the Wii Remote). When the Wii Remote is at rest pitch can be calculated from the force of gravity alone. However, when the Wii Remote is accelerating one must approximate the pitch based off its last known value.

# Calculation #

To calculate pitch purely with data from the accelerometers the Wii Remote must be at rest. This calculation can be performed using:
```
arcsin(ay) * -1 // Multiply by -1 to make the pitch negative when the Wii Remote is tilted down
```
However, as y is turned towards being parallel to the axis of gravity it will begin to lose resolution and become less accurate. For this reason this method is only truly useful between ±π/4. Also using this method will only result in values between ±π/2. Past that we must also know the quadrant that the pitch is in because we will obtain the same values at 0 radians as we will at 3π/2 radians.
To solve this problem one must use two accelerometers. For this one can simply calculate the arctangent of az/ay:
```
arctan2(az, ay) - π/2; // Subtract π/2 to give it the same orientation as the method above 
```
Using this function will result in values between π/2 radians and -3π/2 radians.
One can also use all three accelerometers to find the pitch of the Wii Remote in three dimensions like so:
```
arctan2(ay, sqrt( sqr(ax) + sqr(az) )) * -1
```
However, this suffers from many of the same limitations as the first method, using only one accelerometer.