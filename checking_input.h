#pragma once
#include <iostream>
#include <string>
#include <vector>

//#ifndef HW1_POLYGONE_CHECKING_INPUT_H
//#define HW1_POLYGONE_CHECKING_INPUT_H
enum ParseErrors
{
    SUCCESS = 0,
    NOT_ENOUGH_ARGUMENTS = -2,
    TO_MANY_ARGUMENTS = -3,
    FILE_WAS_NOT_OPENED = -4,
    NOT_ENOUGH_DATA_FOR_POLYGON = -5,
    WRONG_COORDINATES = -6
};

ParseErrors check_input(int argc, char **argv, std::string &path,
                        std::vector<double> &x_polygone,
                        std::vector<double> &y_polygone,
                        double &point_x, double &point_y);
//#endif //HW1_POLYGONE_CHECKING_INPUT_H


std::string get_error_name(ParseErrors err_info);