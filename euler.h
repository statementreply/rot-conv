// MIT License
// Copyright (c) 2018 statementreply

#pragma once

#include "quat.h"

namespace rotconv {
    // Yaw-pitch-roll Euler angles (Z-Y'-X" or X-Y-Z)
    template<class Real>
    struct EulerAngles {
        Real roll;  // x
        Real pitch; // y
        Real yaw;   // z
    };

    // Convert from quaternion to Euler angles
    // Done right (hopefully), i.e. numerically stable
    template<class Real>
    EulerAngles<Real> eulerAngles(const Quat<Real>& q);
}

#include "euler.inl"
