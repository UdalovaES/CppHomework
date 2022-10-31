////#include <cmath>
#include <iostream>
#include <vector>
#include "Counter.h"
#include "finding_errors.h"
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{
    std::string path;
    std::vector<double> x_polygone;
    std::vector<double> y_polygone;
    double point_x;
    double point_y;

    if (processing(argc, argv, path, x_polygone, y_polygone, point_x, point_y) < 0)
    {
        exit (-1);
    }

    // count sum of angles
    double result = 0;
    double angle;

    for (int i = 0; i < x_polygone.size() - 1; i++) {
        angle = angle_counter(point_x, point_y, x_polygone[i], x_polygone[i + 1], y_polygone[i],
                                        y_polygone[i + 1]);
        if (abs(angle - M_PI) <= 0.05 * M_PI){
            std::cout << "The point (" << point_x << "," << point_y << ") is on the edge of the poly" << std::endl;
            return 0;
        }
        else
        {
            result += angle;
        }
    }

    if (abs(result - 2 * M_PI) <= 0.1 * 2 * M_PI) {
            std::cout << "The point (" << point_x << "," << point_y << ") is inside the polygon" << std::endl;
    } else {
        std::cout << "The point (" << point_x << "," << point_y << ") is outside the polygon" << std::endl;
    }
    return 0;
}