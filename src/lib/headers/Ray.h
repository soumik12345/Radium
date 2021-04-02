//
// Created by 19sou on 01-04-2021.
//

#ifndef RADIUM_RAY_H
#define RADIUM_RAY_H

#include "Vector3.h"

enum SurfaceReflectionType {DIFFUSE, SPECULAR, REFRACTED};

class Ray {

private:

    Vector3 origin, direction;

public:

    Ray(Vector3 origin, Vector3 direction): origin(origin), direction(direction) {}

    Vector3 getOrigin() const { return origin; }
    Vector3 getDirection() const { return direction; }
};

#endif //RADIUM_RAY_H
