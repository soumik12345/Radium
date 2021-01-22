#include <iostream>

#include "image_ppm.hpp"


class MyRenderer: public PPMRenderer {

public:
    MyRenderer(int height, int width): PPMRenderer(height, width) {}

    void render(std::string filePath) {

        std::ofstream file(filePath);

        file << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

        for(int j = imageHeight - 1; j >= 0; j--) {

            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

            for(int i = 0; i < imageWidth; i++) {

                ColorRGB pixelColor(
                        double(i) / (imageWidth - 1),
                        double(j) / (imageHeight - 1),
                        0.75);

                writeColor(file, pixelColor);
            }
        }

        file.close();
    }
};


int main() {

    PPMRenderer* renderer1 = new PPMRenderer(256, 256);
    renderer1->render("./image_1.ppm");

    MyRenderer* renderer2 = new MyRenderer(256, 256);
    renderer2->render("./image_2.ppm");

    return 0;
}
