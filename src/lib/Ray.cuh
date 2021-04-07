#ifndef RADIUM_RAY_H
#define RADIUM_RAY_H


#include <iostream>
#include <cuda_runtime.h>
#include <vector_types.h>
#include "device_launch_parameters.h"


enum Materials {
    DIFFUSE,
    SPECULAR,
    REFRACTED
};


class Ray {

public:

    float3 origin, direction;

    __device__ Ray(float3 origin, float3 direction):
    origin(origin), direction(direction) {} 

};
