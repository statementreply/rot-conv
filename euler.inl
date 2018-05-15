// MIT License
// Copyright (c) 2018 statementreply

#include <cmath>
#include <limits>

namespace rotconv {
    // Convert from quaternion to Euler angles
    // Done right (hopefully), i.e. numerically stable
    template<class Real>
    EulerAngles<Real> eulerAngles(const Quat<Real>& q) {
        Real ure = q.w - q.y;
        Real uim = q.z + q.x;
        Real vre = q.w + q.y;
        Real vim = q.z - q.x;
        Real sp = Real(2) * (q.w * q.y - q.z * q.x);
        Real cp = std::hypot(ure, uim) * std::hypot(vre, vim);
        Real pitch = std::atan2(sp, cp);

        using Limits = std::numeric_limits<Real>;
        constexpr Real Thres = Limits::min() / Limits::epsilon();
        if (cp <= Thres) {
            if (cp == Real(0)) {
                // Singularity
                Real yaw = Real(2) * std::atan(q.z / q.w);
                Real roll = Real(0);
                return {roll, pitch, yaw};
            } else {
                // Prevent underflow
                constexpr Real Scale = Real(1) / Limits::epsilon();
                ure *= Scale;
                uim *= Scale;
                vre *= Scale;
                vim *= Scale;
            }
        }

        Real rr = ure * vre;
        Real ii = uim * vim;
        Real ri = ure * vim;
        Real ir = uim * vre;
        Real yaw = std::atan2(ir + ri, rr - ii);
        Real roll = std::atan2(ir - ri, rr + ii);
        return {roll, pitch, yaw};
    }
}
