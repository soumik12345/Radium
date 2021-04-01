//
// Created by 19sou on 02-04-2021.
//

#include "Renderer.h"

void Renderer::addObject(Sphere hittableObject) {
    hittableObjects.push_back(hittableObject);
}

Vector3 Renderer::radiance(const Ray &ray, int depth, unsigned short *seed) {
    double t;
    int objectId = 0;
    if (!intersect(ray, t, objectId))
        return Vector3();
    Sphere &hittableObject = hittableObjects[objectId];
    Vector3 x = ray.getOrigin() + ray.getDirection() * t;
    Vector3 n = (x - hittableObject.getPosition()).normalize();
    Vector3 nl = n.dotProduct(ray.getDirection()) < 0 ? n : n * -1;
    Vector3 f = hittableObject.getColor();
    double p = f.getX() > f.getY() && f.getX() > f.getZ() ? f.getX() : f.getY() > f.getZ() ? f.getY() : f.getZ();

    return Vector3();
}
