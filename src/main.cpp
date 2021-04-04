#include "Radium.h"


int main() {

    Renderer renderer(1024, 768, 40);

//    renderer.setCameraPosition(50, 50, 295.6);
//    renderer.setCameraDirection(0, -0.042612, -1);

    renderer.importCamera("../scenes/cameras/demo_4_camera.csv");
    renderer.importWorld("../scenes/worlds/demo_4_world.csv");

    renderer.render(false);

//    renderer.exportWorld("demo_4_world.csv");
//    renderer.exportCamera("demo_4_camera.csv");

    return 0;
}
