#include <iostream>

#include "Radium.hpp"


class MyRenderer: public PPMRenderer {

public:
    MyRenderer(Image image, Camera camera): PPMRenderer(image, camera) {}

    ColorRGB GetRayColor(Ray ray, HittableList world, int depth) {

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
        auto t = 0.5 * (unitDirection.getX() + 1.0);
        ColorRGB rayColor = (1.0 - t) * ColorRGB(1.0, 1.0, 1.0) + t * ColorRGB(0, 0, 0.7);
        return rayColor;
    }
};


int main() {

    auto aspectRatio = 16.0 / 9.0;
    auto viewPortHeight = 2.0;
    auto viewPortWidth = aspectRatio * viewPortHeight;
    int samplesPerPixel = 100;
    int maxDepth = 50;

    HittableList world;
    world.add(std::make_shared<Sphere>(Point3(0,0,-1), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0,-100.5,-1), 100));

    // ***************** Demo 1 ***************** //

    Image image1 (16.0, 9.0, 400);
    Camera camera1(viewPortWidth, viewPortHeight, 1.0);

    PPMRenderer* renderer1 = new PPMRenderer(image1, camera1);
    renderer1->render(world, samplesPerPixel, maxDepth, "./image_1.ppm");

    // ***************** Demo 2 ***************** //
    Image image2(16.0, 9.0, 400);
    Camera camera2(viewPortWidth, viewPortHeight, 1.0);

    MyRenderer* renderer2 = new MyRenderer(image2, camera2);
    renderer2->render(world, samplesPerPixel, maxDepth, "./image_2.ppm");

    return 0;
}
