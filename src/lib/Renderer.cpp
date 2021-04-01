//
// Created by 19sou on 02-04-2021.
//

#include "Renderer.h"

void Renderer::addObject(Sphere hittableObject) {
    hittableObjects.push_back(hittableObject);
}

Vector3 Renderer::radiance(const Ray &ray, int depth, unsigned short *seed) {
    double t;
    int objectId = 0;
    if (!intersect(ray, t, objectId))
        return Vector3();
    Sphere &hittableObject = hittableObjects[objectId];
    Vector3 x = ray.getOrigin() + ray.getDirection() * t;
    Vector3 n = (x - hittableObject.getPosition()).normalize();
    Vector3 nl = n.dotProduct(ray.getDirection()) < 0 ? n : n * -1;
    Vector3 f = hittableObject.getColor();
    double p = f.getX() > f.getY() && f.getX() > f.getZ() ? f.getX() : f.getY() > f.getZ() ? f.getY() : f.getZ();
    if (++depth > 5) {
        if (erand48(seed) < p)
            f = f * (1 / p);
        else
            return hittableObject.getEmission();
    }
    if (hittableObject.getMaterial() == DIFFUSE) {
        double r1 = 2 * M_PI * erand48(seed);
        double r2 = erand48(seed);
        double r2s = sqrt(r2);
        Vector3 w = nl;
        Vector3 u = ((fabs(w.getX()) > .1 ? Vector3(0, 1, 0) : Vector3(1, 0, 0)) % w).normalize();
        Vector3 v = w % u;
        Vector3 d = (u * cos(r1) * r2s + v * sin(r1) * r2s + w * sqrt(1 - r2)).normalize();
        return hittableObject.getEmission() + f.multiply(radiance(Ray(x, d), depth, seed));
    }
    else if (hittableObject.getMaterial() == SPECULAR) {
        return hittableObject.getEmission() + f.multiply(radiance(Ray(
                x, ray.getDirection() - n * 2 * n.dotProduct(ray.getDirection())), depth, seed));
    }
    Ray reflectedRay(x, ray.getDirection() - n * 2 * n.dotProduct(ray.getDirection()));
    bool into = n.dotProduct(nl) > 0;
    double nc = 1, nt = 1.5, cos2t;
    double  nnt = into ? nc / nt : nt / nc;
    double ddn = ray.getDirection().dotProduct(nl);
    if ((cos2t = 1 - nnt * nnt * (1 - ddn * ddn)) < 0)
        return hittableObject.getEmission() + f.multiply(radiance(reflectedRay, depth, seed));
    Vector3 tDirection = (ray.getDirection() * nnt - n * ((into ? 1 : -1) * (ddn * nnt + sqrt(cos2t)))).normalize();
    double a = nt - nc;
    double b = nt + nc;
    double R0 = a * a / (b * b);
    double c = 1 - (into ? -ddn : tDirection.dotProduct(n));
    double Re = R0 + (1 - R0) * c * c * c * c * c;
    double Tr = 1 - Re;
    double P = .25 + .5 * Re;
    double RP = Re / P;
    double TP = Tr / (1 - P);
    return hittableObject.getEmission() + f.multiply(depth > 2 ? (erand48(seed) < P ?
            radiance(reflectedRay, depth, seed) * RP : radiance(Ray(x, tDirection), depth, seed) * TP) :
            radiance(reflectedRay, depth, seed) * Re + radiance(Ray(x, tDirection), depth, seed) * Tr);
}
