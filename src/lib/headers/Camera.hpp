//
// Created by Soumik Rakshit on 23/01/21.
//

#ifndef RAY_TRACER_CAMERA_HPP
#define RAY_TRACER_CAMERA_HPP


#include "Vector3.hpp"
#include "Ray.hpp"


class Camera {

public:

    Camera() {
        this->origin = Point3(0, 0, 0);

        auto aspectRatio = 16.0 / 9.0;
        auto viewPortHeight = 2.0;
        auto viewPortWidth = aspectRatio * viewPortHeight;

        this->horizontal = Vector3(viewPortWidth, 0, 0);
        this->vertical = Vector3(0, viewPortHeight, 0);
        this->lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vector3(0, 0, 1.0);
    }

    Camera(float viewportWidth, float viewportHeight, float focalLength) {
        this->origin = Point3(0, 0, 0);
        this->horizontal = Vector3(viewportWidth, 0, 0);
        this->vertical = Vector3(0, viewportHeight, 0);
        this->lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vector3(0, 0, focalLength);
    }

    Camera(Camera* camera) {
        this->origin = camera->origin;
        this->horizontal = camera->horizontal;
        this->vertical = camera->vertical;
        this->lowerLeftCorner = camera->lowerLeftCorner;
    }

    void SetOrigin() {
        this->origin = Point3(0, 0, 0);
    }

    void SetHorizontal(Vector3 horizontal) {
        this->horizontal = horizontal;
    }

    void SetVertical(Vector3 vertical) {
        this->vertical = vertical;
    }

    void SetLowerLeftCorner(Vector3 lowerLeftCorner) {
        this->lowerLeftCorner = lowerLeftCorner;
    }

    void Set(Camera camera) {
        this->origin = camera.origin;
        this->horizontal = camera.horizontal;
        this->vertical = camera.vertical;
        this->lowerLeftCorner = camera.lowerLeftCorner;
    }

    Ray GetRay(double u, double v) const {
        return Ray(
                this->origin,
                this->lowerLeftCorner + u * this->horizontal + v * this->vertical - this->origin);
    }

    Point3 origin;
    Vector3 horizontal, vertical, lowerLeftCorner;

};


#endif //RAY_TRACER_CAMERA_HPP
