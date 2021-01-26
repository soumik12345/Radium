//
// Created by Soumik Rakshit on 25/01/21.
//

#ifndef RAY_TRACER_HITTABLE_HPP
#define RAY_TRACER_HITTABLE_HPP

#include <memory>
#include <vector>

#include "Ray.hpp"
#include "Vector3.hpp"


struct HitRecord {
    Point3 point;
    Vector3 normal;
    double t;
    bool frontFace;

    inline void SetFaceNormal(Ray* ray, Vector3 outwardNormal) {
        frontFace = DotProduct(ray->GetDirection(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};


class Hittable {

public:
    virtual bool Hit(Ray* ray, double tMin, double tMax, HitRecord& hitRecord) const = 0;
};


class HittableList: public Hittable {

public:
    HittableList() {}

    HittableList(std::shared_ptr<Hittable> object) { this->add(object); }

    void add(std::shared_ptr<Hittable> object) { this->objects.push_back(object); }

    void clear() { this->objects.clear(); }

    virtual bool Hit(Ray* ray, double tMin, double tMax, HitRecord& hitRecord) const override;

    void Set(HittableList hittableList) { this->objects = hittableList.objects; }

    std::vector<std::shared_ptr<Hittable>> objects;
};


#endif //RAY_TRACER_HITTABLE_HPP
