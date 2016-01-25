# Introduction #

The altitude of a triangle which has two points on opposite sides of the sensor bar and one point on the end of the Wii Remote and which rests on a plane extending from the center of the sensor bar can be calculated through a simple relationship between the actual distance from the sensor bar to the Wii Remote (on a plane) and the perceived distance between the IR points.

# Calculations #

The distance of the Wii Remote from the sensor bar is inversely proportional to the perceived distance between the two infrared points.
Therefore the relationship between the two can be expressed as:
```
d = k / ∆x
```
where d is the physical distance along the sensor bar's plane, ∆x is the perceived distance between the first two IR points, and k is some constant.

Using the one of the following measurements obtained by a member of [WiiLi](http://www.wiili.org)
| Distance (meters) | Dot ∆x |
|:------------------|:-------|
| 0.3               | 860    |
| 0.5               | 535    |
| 1.0               | 268    |
| 1.5               | 176    |
| 2.0               | 132    |
| 2.5               | 106    |
| 3.0               | 87     |
| 3.5               | 75     |
| 4.0               | 65     |

we can estimate the value of k:
```
2 ≈ k / 132

k ≈ 264
```

_ergo:_
```
d ≈ 264 / ∆x
```