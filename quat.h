// MIT License
// Copyright (c) 2018 statementreply

#pragma once

namespace rotconv {
    // Quaternion for 3D rotation
    template<class Real>
    struct Quat {
        Real w;
        Real x;
        Real y;
        Real z;
    };
}
