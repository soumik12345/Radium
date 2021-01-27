//
// Created by Soumik Rakshit on 22/01/21.
//

#ifndef RAY_TRACER_VECTOR3_HPP
#define RAY_TRACER_VECTOR3_HPP

#include <iostream>
#include <cmath>

#include "utils.hpp"

class Vector3 {

public:
    Vector3(): elements{0, 0, 0} {};
    Vector3(double x, double y, double z): elements{x, y, z} {};

    double getX() const { return elements[0]; }
    double getY() const { return elements[1]; }
    double getZ() const { return elements[2]; }

    Vector3 operator-() const { return Vector3(-elements[0], -elements[1], -elements[2]); }
    double operator[](int i) const { return elements[i]; }
    double& operator[](int i) { return elements[i]; }

    Vector3& operator+=(const Vector3 &v) {
        elements[0] += v.elements[0];
        elements[1] += v.elements[1];
        elements[2] += v.elements[2];
        return *this;
    }

    Vector3& operator*=(const double t) {
        elements[0] *= t;
        elements[1] *= t;
        elements[2] *= t;
        return *this;
    }

    Vector3& operator/=(const double t) {
        return *this *= 1/t;
    }

    double length() const {
        return std::sqrt(LengthSquared());
    }

    double LengthSquared() const {
        return elements[0] * elements[0] + elements[1] * elements[1] + elements[2] * elements[2];
    }

    double elements[3];
};


using Point3 = Vector3;   // 3D point
using ColorRGB = Vector3;    // RGB color


inline std::ostream& operator<<(std::ostream &out, const Vector3 &v) {
    return out << v.elements[0] << ' ' << v.elements[1] << ' ' << v.elements[2];
}

inline Vector3 operator+(const Vector3 &u, const Vector3 &v) {
    return Vector3(
            u.elements[0] + v.elements[0],
            u.elements[1] + v.elements[1],
            u.elements[2] + v.elements[2]);
}

inline Vector3 operator-(const Vector3 &u, const Vector3 &v) {
    return Vector3(
            u.elements[0] - v.elements[0],
            u.elements[1] - v.elements[1],
            u.elements[2] - v.elements[2]);
}

inline Vector3 operator*(const Vector3 &u, const Vector3 &v) {
    return Vector3(
            u.elements[0] * v.elements[0],
            u.elements[1] * v.elements[1],
            u.elements[2] * v.elements[2]);
}

inline Vector3 operator*(double t, const Vector3 &v) {
    return Vector3(t*v.elements[0], t*v.elements[1], t*v.elements[2]);
}

inline Vector3 operator*(const Vector3 &v, double t) {
    return t * v;
}

inline Vector3 operator/(Vector3 v, double t) {
    return (1/t) * v;
}

inline double DotProduct(const Vector3 &u, const Vector3 &v) {
    return u.elements[0] * v.elements[0]
           + u.elements[1] * v.elements[1]
           + u.elements[2] * v.elements[2];
}

inline Vector3 CrossProduct(const Vector3 &u, const Vector3 &v) {
    return Vector3(
            u.elements[1] * v.elements[2] - u.elements[2] * v.elements[1],
            u.elements[2] * v.elements[0] - u.elements[0] * v.elements[2],
            u.elements[0] * v.elements[1] - u.elements[1] * v.elements[0]);
}

inline Vector3 GetUnitVector(Vector3 v) {
    return v / v.length();
}

inline Vector3 GetRandomVector3() {
    return Vector3(GetRandomNumber(), GetRandomNumber(), GetRandomNumber());
}

inline Vector3 GetRandomVector3(double min, double max) {

    return Vector3(
            GetRandomNumber(min, max),
            GetRandomNumber(min, max),
            GetRandomNumber(min, max));
}

inline Vector3 RandomVectorInUnitSphere() {
    while (true) {
        auto p = GetRandomVector3(-1, 1);
        if (p.LengthSquared() >= 1)
            continue;
        return p;
    }
}

inline Vector3 GetRandomUnitVector3() {
    return GetUnitVector(RandomVectorInUnitSphere());
}


#endif //RAY_TRACER_VECTOR3_HPP
