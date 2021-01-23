//
// Created by Soumik Rakshit on 23/01/21.
//

#ifndef RAY_TRACER_RAY_H
#define RAY_TRACER_RAY_H

#include "Vector3.hpp"


class Ray {

public:
    Ray() {}
    Ray(const Point3 &, const Vector3 &);

    Point3 GetOrigin();
    Vector3 GetDirection();

    Point3 at(double);

private:
    Point3 origin;
    Vector3 direction;

};


#endif //RAY_TRACER_RAY_H
