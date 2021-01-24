//
// Created by Soumik Rakshit on 24/01/21.
//

#ifndef RAY_TRACER_SPHERE_HPP
#define RAY_TRACER_SPHERE_HPP


#include "Vector3.hpp"
#include "Ray.hpp"


class Sphere {

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

    double Hit(Ray* ray) {
        Vector3 originToCenter = ray->GetOrigin() - this->center;
        auto a = DotProduct(ray->GetDirection(), ray->GetDirection());
        auto b = 2.0 * DotProduct(originToCenter, ray->GetDirection());
        auto c = DotProduct(originToCenter, originToCenter) - this->radius * this->radius;
        auto discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return -1.0;
        else
            return (-b - std::sqrt(discriminant) ) / (2.0 * a);
    }

    Point3 center;
    double radius;
};


#endif //RAY_TRACER_SPHERE_HPP
