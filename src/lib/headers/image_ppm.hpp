//
// Created by Soumik Rakshit on 22/01/21.
//

#ifndef RAY_TRACER_IMAGE_PPM_HPP
#define RAY_TRACER_IMAGE_PPM_HPP

#include <iostream>
#include <fstream>
#include <vector>

#include "Vector3.hpp"


class PPMRenderer {

public:
    PPMRenderer(int, int);

    int GetImageWidth();
    int GetImageHeight();

    void SetImageWidth(int);
    void SetImageHeight(int);

    void writeColor(std::ostream &, ColorRGB);

    virtual void render(std::string);

protected:
    int imageWidth, imageHeight;
};


#endif //RAY_TRACER_IMAGE_PPM_HPP
