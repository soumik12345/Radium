//
// Created by Soumik Rakshit on 22/01/21.
//

#include "image_ppm.hpp"


PPMRenderer::PPMRenderer(int height, int width) {

    imageHeight = height;
    imageWidth = width;
}

int PPMRenderer::GetImageHeight() {
    return imageHeight;
}

int PPMRenderer::GetImageWidth() {
    return imageWidth;
}

void PPMRenderer::SetImageHeight(int height) {
    imageHeight = height;
}

void PPMRenderer::SetImageWidth(int width) {
    imageWidth = width;
}

void PPMRenderer::writeColor(std::ostream &outputStream, ColorRGB pixelColor) {

    outputStream << static_cast<int>(255.999 * pixelColor.getX()) << ' '
                 << static_cast<int>(255.999 * pixelColor.getY()) << ' '
                 << static_cast<int>(255.999 * pixelColor.getZ()) << '\n';
}

void PPMRenderer::render(std::string filePath) {

    std::ofstream file(filePath);

    file << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for(int j = imageHeight - 1; j >= 0; j--) {

        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for(int i = 0; i < imageWidth; i++) {

            ColorRGB pixelColor(
                    double(i) / (imageWidth - 1),
                    double(j) / (imageHeight - 1),
                    0.25);

            writeColor(file, pixelColor);
        }
    }

    file.close();
}
