//
// Created by Soumik Rakshit on 23/01/21.
//

#include "Ray.hpp"


Ray::Ray(const Point3 &origin, const Vector3 &direction) {
    this->origin = origin;
    this->direction = direction;
}

Point3 Ray::GetOrigin() {
    return origin;
}

Vector3 Ray::GetDirection() {
    return direction;
}

Point3 Ray::at(double t) {
    return origin + t * direction;
}
