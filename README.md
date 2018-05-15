# rot-conv
Get yaw-pitch-roll (Euler angles) of 3-D rotations, done right

## What is it
rot-conv is a minimized C++ library for conversion between 3-D rotation representations. It provides *numerically stable* implementation of a few operations that can be numerically unstable with naïve algorithm.

Conversion to yaw-pitch-roll is especially prone to numerical unstability due to its singularities at pitch=±90°. Some code I found on the web ([[1]](https://github.com/g-truc/glm/blob/0.9.8.5/glm/gtc/quaternion.inl#L562-L584)[[2]](https://stackoverflow.com/a/18115837)[[3]](https://stackoverflow.com/a/18436193)[[4]](https://www.learnopencv.com/rotation-matrix-to-euler-angles/)) fails at the singularities and/or loses significant digits near them.

Currently available:
* Quaternion to yaw-pitch-roll conversion

Operations without numerical stability issues (e.g. axis-angle to quaternion) are not included in this library.

## Requirements
* C++11 compiler

## License
[MIT License](https://github.com/statementreply/rot-conv/blob/master/LICENSE)

## TODO
* Rotation matrix to yaw-pitch-roll conversion
* Rotation matrix normalization
