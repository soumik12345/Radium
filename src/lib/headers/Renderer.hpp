//
// Created by Soumik Rakshit on 22/01/21.
//

#ifndef RAY_TRACER_RENDERER_HPP
#define RAY_TRACER_RENDERER_HPP

#include <iostream>
#include <fstream>
#include <vector>

#include "Core.hpp"
#include "Vector3.hpp"


class PPMRenderer {

public:
    PPMRenderer(Image*);

    int GetImageWidth();
    int GetImageHeight();

    void writeColor(std::ostream &, ColorRGB);

    virtual void render(std::string);

protected:
    Image image;
};


#endif //RAY_TRACER_RENDERER_HPP
