#include <iostream>

#include "Renderer.hpp"


class MyRenderer: public PPMRenderer {

public:
    MyRenderer(Image image): PPMRenderer(image) {}

    void render(std::string filePath) {

        std::ofstream file(filePath);

        file << "P3\n" << this->GetImageWidth() << ' ' << this->GetImageHeight() << "\n255\n";

        for(int j = this->GetImageHeight() - 1; j >= 0; j--) {

            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

            for(int i = 0; i < this->GetImageWidth(); i++) {

                ColorRGB pixelColor(
                        double(i) / (this->GetImageWidth() - 1),
                        double(j) / (this->GetImageHeight() - 1),
                        0.75);

                writeColor(file, pixelColor);
            }
        }

        file.close();
    }
};


int main() {

    Image image1(16.0, 9.0, 400);
    PPMRenderer* renderer1 = new PPMRenderer(image1);
    renderer1->render("./image_1.ppm");

    Image image2(16.0, 9.0, 400);
    MyRenderer* renderer2 = new MyRenderer(image2);
    renderer2->render("./image_2.ppm");

    return 0;
}
