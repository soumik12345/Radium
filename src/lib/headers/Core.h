//
// Created by 19sou on 01-04-2021.
//

#ifndef RADIUM_CORE_H
#define RADIUM_CORE_H

#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"

#include <cstdlib>


inline double clamp(double x) {
    return x < 0 ? 0 : x > 1 ? 1 : x;
}

inline int toInt(double x) {
    return int(pow(clamp(x), 1 / 2.2) * 255 + .5);
}

#endif //RADIUM_CORE_H
