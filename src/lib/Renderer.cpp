//
// Created by Soumik Rakshit on 22/01/21.
//

#include "Renderer.hpp"


PPMRenderer::PPMRenderer(Image image, Camera camera, Sphere sphere) {

    this->image.Set(image);
    this->camera.Set(camera);
    this->sphere.Set(sphere);
}

int PPMRenderer::GetImageHeight() {
    return this->image.imageHeight;
}

int PPMRenderer::GetImageWidth() {
    return this->image.imageWidth;
}

ColorRGB PPMRenderer::GetRayColor(Ray* ray) {

    if(this->sphere.Hit(ray)) {
        return ColorRGB(1, 0, 0);
    }
    Vector3 unitDirection = GetUnitVector(ray->GetDirection());
    auto t = 0.5 * (unitDirection.getY() + 1.0);
    ColorRGB rayColor = (1.0 - t) * ColorRGB(1.0, 1.0, 1.0) + t * ColorRGB(0.5, 0.7, 1.0);
    return rayColor;
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

            auto u = double(i) / (this->GetImageWidth() - 1);
            auto v = double(j) / (this->GetImageHeight() - 1);

            Ray* ray = new Ray(
                    camera.origin,
                    camera.lowerLeftCorner + u * camera.horizontal + v * camera.vertical - camera.origin);

            ColorRGB pixelColor = GetRayColor(ray);
            writeColor(file, pixelColor);
        }
    }

    file.close();
}
