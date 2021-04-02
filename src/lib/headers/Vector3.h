//
// Created by 19sou on 01-04-2021.
//

#ifndef RADIUM_VECTOR3_H
#define RADIUM_VECTOR3_H

#include <cmath>
#include <cstdio>


class Vector3 {

private:

    double x, y, z;

public:

    Vector3();
    Vector3(double, double, double);

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double X) { this->x = X; }
    void setY(double Y) { this->y = Y; }
    void setZ(double Z) { this->z = Z; }

    Vector3 operator + (const Vector3&) const;
    Vector3 operator - (const Vector3&) const;
    Vector3 operator * (double) const;
    Vector3 operator % (const Vector3&) const;

    Vector3 multiply (const Vector3&) const;
    Vector3 normalize ();

    double dotProduct (const Vector3&) const;

    void display() const;
};


#endif //RADIUM_VECTOR3_H
