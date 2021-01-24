#include <iostream>

#include "Renderer.hpp"


class MyRenderer: public PPMRenderer {

public:
    MyRenderer(Image image, Camera camera, Sphere sphere): PPMRenderer(image, camera, sphere) {}

    ColorRGB GetRayColor(Ray* ray) {

        auto t = this->sphere.Hit(ray);
        if (t > 0.0) {
            Vector3 n = GetUnitVector(ray->at(t) - this->sphere.center);
            return 0.5 * ColorRGB(n.getX() + 1, n.getY() + 1, n.getZ() + 1);
        }
        Vector3 unitDirection = GetUnitVector(ray->GetDirection());
        t = 0.5 * (unitDirection.getX() + 1.0);
        ColorRGB rayColor = (1.0 - t) * ColorRGB(1.0, 1.0, 1.0) + t * ColorRGB(0, 0, 0.7);
        return rayColor;
    }

};


int main() {

    // Demo 1
    Image image1 (16.0, 9.0, 400);
    auto aspectRatio = 16.0 / 9.0;
    auto viewPortHeight = 2.0;
    auto viewPortWidth = aspectRatio * viewPortHeight;
    Camera camera1(viewPortWidth, viewPortHeight, 1.0);
    Sphere sphere1(Point3(0, 0, -1), 0.5);
    PPMRenderer* renderer1 = new PPMRenderer(image1, camera1, sphere1);
    renderer1->render("./image_1.ppm");

    // Demo 2
    Image image2(16.0, 9.0, 400);
    Camera camera2(viewPortWidth, viewPortHeight, 1.0);
    Sphere sphere2(Point3(0, 0, -1), 0.5);
    MyRenderer* renderer2 = new MyRenderer(image2, camera2, sphere2);
    renderer2->render("./image_2.ppm");

    return 0;
}
