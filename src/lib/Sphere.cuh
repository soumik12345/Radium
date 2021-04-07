#ifndef RADIUM_SPHERE_H
#define RADIUM_SPHERE_H

#include "Ray.h"
#include "Utils/DotProduct.cuh"


class Sphere {

public:

    float radius;
    float3 position, emission, color;
    Material material;

    __device__ float intersect_sphere(const Ray &ray) const {
        float3 originToCenter = position - ray.origin;
        float t;
        float epsilon = 0.0001f;
        float b = dotProduct(originToCenter, ray.direction);
        float discriminant = b * b - dotProduct(originToCenter, originToCenter) + radius * radius;
        if (discriminant < 0)
            return 0;
        else
            discriminant = sqrtf(discriminant);
            return (t = b - discriminant) > epsilon ? t : ((t = b + discriminant)>epsilon ? t : 0);
    }

};
