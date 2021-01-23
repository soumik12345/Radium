//
// Created by Soumik Rakshit on 22/01/21.
//

#ifndef RAY_TRACER_RENDERER_HPP
#define RAY_TRACER_RENDERER_HPP

#include <iostream>
#include <fstream>
#include <vector>

#include "Image.hpp"
#include "Vector3.hpp"
#include "Camera.hpp"
#include "Ray.h"


class PPMRenderer {

public:
    PPMRenderer(Image*, Camera*);

    int GetImageWidth();
    int GetImageHeight();

    virtual ColorRGB GetRayColor(Ray*);

    void writeColor(std::ostream &, ColorRGB);
    void render(std::string);

protected:
    Image image;
    Camera camera;
};


#endif //RAY_TRACER_RENDERER_HPP
