//
// Created by 19sou on 02-04-2021.
//

#ifndef RADIUM_RENDERER_H
#define RADIUM_RENDERER_H


#include "Sphere.h"
#include "Core.h"
#include "Ray.h"

#include <vector>
#include <cstdlib>
#include <cmath>


class Renderer {

private:

    std::vector<Sphere> hittableObjects;

public:

    void addObject(Sphere hittableObject);

    bool intersect(const Ray &ray, double &t, int &objectId) {
        double n = hittableObjects.size(), d;
        double infinity = t = 1e20;
        for(int i = int(n); i-- ; )
            if ((d = hittableObjects.at(i).intersect(ray)) && d < t) {
                t = d;
                objectId = i;
            }
        return t < infinity;
    }

    Vector3 radiance(const Ray&, int, unsigned short *);

};


#endif //RADIUM_RENDERER_H
