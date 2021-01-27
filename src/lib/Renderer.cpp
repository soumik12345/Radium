//
// Created by Soumik Rakshit on 22/01/21.
//

#include "Renderer.hpp"


PPMRenderer::PPMRenderer(Image image, Camera camera) {

    this->image.Set(image);
    this->camera.Set(camera);
}

int PPMRenderer::GetImageHeight() {
    return this->image.imageHeight;
}

int PPMRenderer::GetImageWidth() {
    return this->image.imageWidth;
}

ColorRGB PPMRenderer::GetRayColor(Ray ray, HittableList world, int depth) {

    HitRecord hitRecord;

    if (depth <= 0)
        return ColorRGB(0, 0, 0);

    if (world.Hit(ray, 0, Infinity, hitRecord)) {
        Point3 target = hitRecord.point + hitRecord.normal + RandomVectorInUnitSphere();
        return 0.5 * this->GetRayColor(
                Ray(hitRecord.point, target - hitRecord.point),
                world, depth - 1);
    }
    Vector3 unitDirection = GetUnitVector(ray.GetDirection());
    auto t = 0.5 * (unitDirection.getY() + 1.0);
    ColorRGB rayColor = (1.0 - t) * ColorRGB(1.0, 1.0, 1.0) + t * ColorRGB(0.5, 0.7, 1.0);
    return rayColor;
}

void PPMRenderer::writeColor(std::ostream &outputStream, ColorRGB pixelColor, int samplesPerPixel) {

    auto r = pixelColor.getX();
    auto g = pixelColor.getY();
    auto b = pixelColor.getZ();

    auto scale = 1.0 / samplesPerPixel;
    r *= scale;
    g *= scale;
    b *= scale;

    outputStream << static_cast<int>(256 * Clamp(r, 0.0, 0.999)) << ' '
                 << static_cast<int>(256 * Clamp(g, 0.0, 0.999)) << ' '
                 << static_cast<int>(256 * Clamp(b, 0.0, 0.999)) << '\n';
}

void PPMRenderer::render(HittableList world, int samplesPerPixel, int maxDepth, std::string filePath) {

    std::ofstream file(filePath);

    file << "P3\n" << this->GetImageWidth() << ' ' << this->GetImageHeight() << "\n255\n";

    tqdm progressBar;

    for(int j = this->GetImageHeight() - 1; j >= 0; j--) {

        progressBar.progress(this->GetImageHeight() - j, this->GetImageHeight());

        for(int i = 0; i < this->GetImageWidth(); i++) {

            ColorRGB pixelColor(0, 0, 0);

            for (int s = 0; s < samplesPerPixel; s++) {

                auto u = (i + GetRandomNumber()) / (this->GetImageWidth() - 1);
                auto v = (j + GetRandomNumber()) / (this->GetImageHeight() - 1);

                Ray ray = this->camera.GetRay(u, v);

                pixelColor += this->GetRayColor(ray, world, maxDepth);
            }

            writeColor(file, pixelColor, samplesPerPixel);
        }
    }

    file.close();
}
