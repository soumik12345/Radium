#include "Radium.h"


int main() {

    Renderer renderer(1024, 768, 40);

    renderer.setCameraPosition(50, 52, 295.6);
    renderer.setCameraDirection(0, -0.042612, -1);

    renderer.addObject(
            Sphere(1e5, Vector3(1e5 + 1, 40.8, 81.6), Vector3(), Vector3(.75, .25, .25), DIFFUSE));
    renderer.addObject(
            Sphere(1e5, Vector3(-1e5 + 99, 40.8, 81.6), Vector3(), Vector3(.25, .25, .75), DIFFUSE));
    renderer.addObject(
            Sphere(1e5, Vector3(50, 40.8, 1e5), Vector3(), Vector3(.75, .75, .75), DIFFUSE));
    renderer.addObject(
            Sphere(1e5, Vector3(50, 40.8, -1e5 + 170), Vector3(), Vector3(), DIFFUSE));
    renderer.addObject(
            Sphere(1e5, Vector3(50, 1e5, 81.6), Vector3(), Vector3(.75, .75, .75), DIFFUSE));
    renderer.addObject(
            Sphere(1e5, Vector3(50, -1e5 + 81.6, 81.6), Vector3(), Vector3(.75, .75, .75), DIFFUSE));
    renderer.addObject(
            Sphere(16.5, Vector3(27, 16.5, 47), Vector3(), Vector3(1, 1, 1) * .999, SPECULAR));
    renderer.addObject(
            Sphere(16.5, Vector3(73, 16.5, 78), Vector3(), Vector3(1, 1, 1) * .999, REFRACTED));
    renderer.addObject(
            Sphere(600, Vector3(50, 681.6 - .27, 81.6), Vector3(12, 12, 12), Vector3(), DIFFUSE));

    renderer.render();

    return 0;
}
