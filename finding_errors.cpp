#include "checking_input.h"
#include <iostream>
#include <vector>
#include "finding_errors.h"

int processing(int argc, char **argv, std::string path, std::vector<double> &x_polygone,
               std::vector<double> &y_polygone, double &point_x, double &point_y)
{
    auto find_mistake = check_input(argc, argv, path, x_polygone, y_polygone, point_x, point_y);

    if ((find_mistake) < 0)
    {
        std::cerr << "Fix the error in entering data: " << get_error_name(find_mistake) << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Successfully parsed command line, filename = "
                  << path << ", x = " << point_x << ", y = " << point_y << std::endl;
    }
    return 0;
}