#include <iostream>

#include "Renderer.hpp"


class MyRenderer: public PPMRenderer {

public:
    MyRenderer(Image* image, Camera* camera): PPMRenderer(image, camera) {}

    ColorRGB GetRayColor(Ray* ray) {

        Vector3 unitDirection = GetUnitVector(ray->GetDirection());
        auto t = 0.5 * (unitDirection.getX() + 1.0);
        ColorRGB rayColor = (1.0 - t) * ColorRGB(1.0, 1.0, 1.0) + t * ColorRGB(0.5, 0.0, 0.0);
        return rayColor;
    }

};


int main() {

    // Demo 1
    Image* image1 = new Image(16.0, 9.0, 400);
    auto aspectRatio = 16.0 / 9.0;
    auto viewPortHeight = 2.0;
    auto viewPortWidth = aspectRatio * viewPortHeight;
    Camera* camera1 = new Camera(viewPortWidth, viewPortHeight, 1.0);
    PPMRenderer* renderer1 = new PPMRenderer(image1, camera1);
    renderer1->render("./image_1.ppm");

    // Demo 2
    Image* image2 = new Image(16.0, 9.0, 400);
    Camera* camera2 = new Camera(viewPortWidth, viewPortHeight, 1.0);
    MyRenderer* renderer2 = new MyRenderer(image2, camera2);
    renderer2->render("./image_2.ppm");

    return 0;
}
