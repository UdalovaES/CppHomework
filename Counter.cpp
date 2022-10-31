#include "Counter.h"
#include <cmath>
#include "math.h"
#include <iostream>

double angle_counter(double x_point, double y_point, double x1, double x2, double y1, double y2)
{

    double cz = 1;
    // specifications of AiO vector
    double ax = x1 - x_point;
    double ay = y1 - y_point;
    double len_a = sqrt(ax * ax + ay * ay);

    // specifications of A(i+1)O vector
    double bx = x2 - x_point;
    double by = y2 - y_point;
    double len_b = pow((bx * bx + by * by), 0.5);

    // checking the direction of the three vectors
    double det = ax * by * cz - bx * ay * cz;
    int sign = (det >= 0) ? 1 : -1;

    double cos_ai = (ax*bx + ay*by) / (len_a * len_b);

    double angle = sign * acos(cos_ai);

    return angle;
}