//
// Created by Soumik Rakshit on 24/01/21.
//

#ifndef RAY_TRACER_SPHERE_HPP
#define RAY_TRACER_SPHERE_HPP


#include "Vector3.hpp"
#include "Ray.hpp"
#include "Hittable.hpp"


class Sphere: public Hittable {

public:

    Sphere() {
        this->center = Point3(0, 0, -1);
        this->radius = 0.5;
    }

    Sphere(Point3 center, double radius) {

        this->center = center;
        this->radius = radius;
    }

    void Set(Sphere sphere) {
        this->center = sphere.center;
        this->radius = sphere.radius;
    }

    virtual bool Hit(Ray* ray, double tMin, double tMax, HitRecord& hitRecord) const override;

    Point3 center;
    double radius;
};


#endif //RAY_TRACER_SPHERE_HPP
