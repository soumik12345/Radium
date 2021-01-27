//
// Created by Soumik Rakshit on 26/01/21.
//

#ifndef RAY_TRACER_UTILS_HPP
#define RAY_TRACER_UTILS_HPP


#include <cstdlib>
#include <random>


const double Infinity = std::numeric_limits<double>::infinity();

const double PI = 3.1415926535897932385;

inline double DegreesToRadians(double degrees) { return degrees * PI / 180.0; }

inline double GetRandomNumber() {

    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double GetRandomNumber(int min, int max) { return min + (max - min) * GetRandomNumber(); }

inline double Clamp(double x, double min, double max) {

    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}


#endif //RAY_TRACER_UTILS_HPP
