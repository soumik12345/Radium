//
// Created by 19sou on 01-04-2021.
//

#include "Vector3.h"


Vector3::Vector3(): x(0), y(0), z(0) {}

Vector3::Vector3(double x, double y, double z): x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(
            x + other.x,
            y + other.y,
            z + other.z);
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(
            x - other.x,
            y - other.y,
            z - other.z);
}

Vector3 Vector3::operator*(double value) const {
    return Vector3(
            x * value,
            y * value,
            z * value);
}

Vector3 Vector3::operator%(const Vector3 &divisor) const {
    return Vector3(
            y * divisor.z - z * divisor.y,
            z * divisor.x - x * divisor.z,
            x * divisor.y - y * divisor.x);
}

Vector3 Vector3::multiply(const Vector3 &other) const {
    return Vector3(
            x * other.x,
            y * other.y,
            z * other.z);
}

Vector3 Vector3::normalize() {
    return *this = *this * (1 / sqrt(x * x + y * y + z * z));
}

double Vector3::dotProduct(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

void Vector3::display() const {
    printf("(%d, %d, %d)", x, y, z);
}
