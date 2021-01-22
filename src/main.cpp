#include <iostream>

#include "image_ppm.hpp"

int main() {

    PPMRenderer renderer(256, 256, "./image_2.ppm");
    renderer.render();

    return 0;
}
