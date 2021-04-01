//
// Created by 19sou on 01-04-2021.
//

#ifndef RADIUM_SPHERE_H
#define RADIUM_SPHERE_H

#include "Vector3.h"
#include "Ray.h"


class Sphere {

private:

    double radius;
    Vector3 position, emission, color;
    SurfaceReflectionType material;

public:

    Sphere(double, Vector3, Vector3, Vector3, SurfaceReflectionType);

    double intersect(const Ray& ray) const;

};

#endif //RADIUM_SPHERE_H
