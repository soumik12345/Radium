#include <iostream>

#include "image_ppm.hpp"

int main() {

    PPMRenderer* renderer = new PPMRenderer(256, 256);
    renderer->render("./image_1.ppm");

    return 0;
}
