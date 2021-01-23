//
// Created by Soumik Rakshit on 22/01/21.
//

#include "Renderer.hpp"


PPMRenderer::PPMRenderer(Image image) {

    this->image = image;
}

int PPMRenderer::GetImageHeight() {
    return this->image.imageHeight;
}

int PPMRenderer::GetImageWidth() {
    return this->image.imageWidth;
}

void PPMRenderer::writeColor(std::ostream &outputStream, ColorRGB pixelColor) {

    outputStream << static_cast<int>(255.999 * pixelColor.getX()) << ' '
                 << static_cast<int>(255.999 * pixelColor.getY()) << ' '
                 << static_cast<int>(255.999 * pixelColor.getZ()) << '\n';
}

void PPMRenderer::render(std::string filePath) {

    std::ofstream file(filePath);

    file << "P3\n" << this->GetImageWidth() << ' ' << this->GetImageHeight() << "\n255\n";

    for(int j = this->GetImageHeight() - 1; j >= 0; j--) {

        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for(int i = 0; i < this->GetImageWidth(); i++) {

            ColorRGB pixelColor(
                    double(i) / (this->GetImageWidth() - 1),
                    double(j) / (this->GetImageHeight() - 1),
                    0.25);

            writeColor(file, pixelColor);
        }
    }

    file.close();
}
