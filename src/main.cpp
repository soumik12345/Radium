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

                int r = static_cast<int>(255.999 * double(i) / (imageWidth - 1));
                int g = static_cast<int>(255.999 * double(j) / (imageHeight - 1));
                int b = static_cast<int>(255.999 * 0.75);

                file << r << " " << g << " " << b << "\n";
            }
        }

        file.close();
    }
};


int main() {

//    PPMRenderer* renderer = new PPMRenderer(256, 256);
//    renderer->render("./image_1.ppm");

    MyRenderer* renderer = new MyRenderer(256, 256);
    renderer->render("./image_2.ppm");

    return 0;
}
