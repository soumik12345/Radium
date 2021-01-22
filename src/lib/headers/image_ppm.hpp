//
// Created by Soumik Rakshit on 22/01/21.
//

#ifndef RAY_TRACER_IMAGE_PPM_HPP
#define RAY_TRACER_IMAGE_PPM_HPP

#include <iostream>
#include <fstream>
#include <vector>


class PPMRenderer {

public:
    PPMRenderer(int, int, std::string);
    ~PPMRenderer();

    int GetImageWidth();
    int GetImageHeight();

    void SetImageWidth(int);
    void SetImageHeight(int);

    void render();

private:
    int imageWidth, imageHeight;

    std::ofstream file;
};


#endif //RAY_TRACER_IMAGE_PPM_HPP
