//
// Created by Soumik Rakshit on 26/01/21.
//

#include "Hittable.hpp"


bool HittableList::Hit(Ray ray, double tMin, double tMax, HitRecord &hitRecord) const {

    HitRecord tempRecords;
    bool hitAnything = false;
    auto closestSoFar = tMax;

    for (auto object : objects) {
        if (object->Hit(ray, tMin, closestSoFar, tempRecords)) {
            hitAnything = true;
            closestSoFar = tempRecords.t;
            hitRecord = tempRecords;
        }
    }

    return hitAnything;
}
