//
// Created by Soumik Rakshit on 23/01/21.
//

#ifndef RAY_TRACER_CORE_HPP
#define RAY_TRACER_CORE_HPP


class Image {

public:

    Image() {
        auto aspectRatio = 16.0 / 9.0;
        this->imageWidth = 400;
        this->imageHeight = static_cast<int>(this->imageWidth / aspectRatio);
    }

    Image(float aspectRatioW, float aspectRationH, int imageWidth) {

        auto aspectRatio = aspectRatioW / aspectRationH;
        this->imageWidth = imageWidth;
        this->imageHeight = static_cast<int>(this->imageWidth / aspectRatio);
    }

    int imageWidth, imageHeight;
};


#endif //RAY_TRACER_CORE_HPP
