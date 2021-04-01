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

inline bool intersect(const Ray &ray, double &t, int &objectId) {
    double n = sizeof(spheres) / sizeof(Sphere), d;
    double infinity = t = 1e20;
    for(int i = int(n); i-- ; )
        if ((d = spheres[i].intersect(ray)) && d < t) {
            t = d;
            objectId = i;
        }
    return t < infinity;
}

#endif //RADIUM_CORE_H
