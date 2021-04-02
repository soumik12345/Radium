//
// Created by 19sou on 01-04-2021.
//

#include "Sphere.h"

Sphere::Sphere(
        double radius, Vector3 position, Vector3 emission,
        Vector3 color, SurfaceReflectionType material):
        radius(radius),position(position), emission(emission),
        color(color), material(material) {}

double Sphere::intersect(const Ray &ray) const {

    Vector3 op = position - ray.getOrigin();
    double t;
    double epsilon = 1e-4;
    double b = op.dotProduct(ray.getDirection());
    double determinant = b * b - op.dotProduct(op) + radius * radius;
    if (determinant < 0)
        return 0;
    else
        determinant = sqrt(determinant);
    return (t = b - determinant) > epsilon ? t : ((t = b + determinant) > epsilon ? t : 0);
}
