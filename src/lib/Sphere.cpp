//
// Created by Soumik Rakshit on 25/01/21.
//

#include "Sphere.hpp"


bool Sphere::Hit(Ray* ray, double tMin, double tMax, HitRecord& hitRecord) const {

    Vector3 originToCenter = ray->GetOrigin() - this->center;
    auto a = ray->GetDirection().LengthSquared();
    auto half_b = DotProduct(originToCenter, ray->GetDirection());
    auto c = originToCenter.LengthSquared() - this->radius * this->radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return false;
    auto discriminantSquare = std::sqrt(discriminant);

    auto root = (-half_b - discriminantSquare) / a;
    if (root < tMin || tMax < root) {
        root = (-half_b + discriminantSquare) / a;
        if (root < tMin || tMax < root)
            return false;
    }

    hitRecord.t = root;
    hitRecord.point = ray->at(hitRecord.t);
    Vector3 outwardNormal = (hitRecord.point - this->center) / this->radius;
    hitRecord.SetFaceNormal(ray, outwardNormal);

    return true;
}
