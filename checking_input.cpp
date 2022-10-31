#include "checking_input.h"
#include <iostream>
#include <fstream>
#include <vector>

ParseErrors check_input(int argc, char **argv, std::string &path, std::vector<double> &x_polygone, std::vector<double> &y_polygone, double &point_x, double &point_y)
{
    if(argc < 4)
    {
        return ParseErrors:: NOT_ENOUGH_ARGUMENTS;
    }
    if (argc > 4)
    {
        return ParseErrors::TO_MANY_ARGUMENTS;
    }

    path = argv[1];
    std::ifstream f;
    f.open(path);
    if (!f.is_open())
    {
        return ParseErrors:: FILE_WAS_NOT_OPENED;
    }

    std::cout << "File was successfully opened" << std::endl;

    std::string x, y;
    while (!f.eof())
    {
        f >> x >> y;
        x_polygone.push_back(std::stod(x));
        y_polygone.push_back(std::stod(y));
    }
    f.close();

    x_polygone.push_back(x_polygone[0]); // add the initial coordinates to make a full shape
    y_polygone.push_back(y_polygone[0]);

    if (x_polygone.size() < 3 || y_polygone.size() < 3)
    {
        return ParseErrors:: NOT_ENOUGH_DATA_FOR_POLYGON;
    }

    std::cout << "Polygone was successfully made" << std::endl;

    try {
        point_x = std::stod(argv[2]);
        point_y = std::stod(argv[3]);
    }
    catch (std::logic_error)
    {
        return ParseErrors::WRONG_COORDINATES;
    }

    std::cout << "Initial coordinates are okay" << std::endl;

    return ParseErrors::SUCCESS;
}

std::string get_error_name(ParseErrors err_info)
{
    switch (err_info)
    {
        case ParseErrors::NOT_ENOUGH_ARGUMENTS:
            return "Not enough arguments";
        case ParseErrors::TO_MANY_ARGUMENTS:
            return "To many arguments";
        case ParseErrors::FILE_WAS_NOT_OPENED:
            return "Path to file is uncorrect";
        case ParseErrors::NOT_ENOUGH_DATA_FOR_POLYGON:
            return "Polygon cannot have less than 3 vertices";
        case ParseErrors::SUCCESS:
            return "No error";
    }
    return "Unknown error";
}
