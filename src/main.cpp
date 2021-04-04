#include "Radium.h"


int main() {

    Renderer renderer(1024, 768, 5000);

    renderer.setCameraPosition(50, 50, 295.6);
    renderer.setCameraDirection(0, -0.042612, -1);

    renderer.importCamera("../scenes/cameras/demo_2_camera.csv");
    renderer.importWorld("../scenes/worlds/demo_2_world.csv");

//    Vector3 center(50, -20, -860);
//
//    renderer.addObject(
//            Sphere(
//                    160,  center + Vector3(0, 600, -500),
//                    Vector3(1, 1, 1) * 2e2, Vector3(), DIFFUSE));
//    renderer.addObject(
//            Sphere(
//                    800, center + Vector3(0, -880, -9120),
//                    Vector3(1, 1, 1) * 2e1, Vector3(), DIFFUSE));
//    renderer.addObject(
//            Sphere(
//                    10000, center + Vector3(0, 0, -200),
//                    Vector3(0.0627, 0.188, 0.569) * 1e0, Vector3(1, 1, 1) * .4, DIFFUSE));
//    renderer.addObject(
//            Sphere(
//                    800, center + Vector3(0, -720, -200),
//                    Vector3(), Vector3(0.110, 0.898, 1.00) * .996, REFRACTED));
//    renderer.addObject(
//            Sphere(
//                    790, center + Vector3(0, -720, -200),
//                    Vector3(), Vector3(.4, .3, .04) * .6, DIFFUSE));
//    renderer.addObject(
//            Sphere(
//                    325, center + Vector3(0, -255, -50),
//                    Vector3(), Vector3(.4, .3, .04) * .8, DIFFUSE));
//    renderer.addObject(
//            Sphere(
//                    275, center + Vector3(0, -205, -33),
//                    Vector3(), Vector3(.02, .3, .02) * .75, DIFFUSE));

    renderer.render(false);
//    renderer.exportWorld("demo_2_world.csv");
//    renderer.exportCamera("demo_2_camera.csv");

    return 0;
}
