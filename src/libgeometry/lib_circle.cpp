#include "lib_circle.h"
#include <cstring>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool wkt_check(string str)
{
    string strValues;
    Circle coordinates;

    if (str.empty())
        return 0;

    for (auto chr : str)
        if (chr == ' ')
            coordinates.space++;
    if (coordinates.space != 1)
        return 0;
    for (auto chr : str)
        if (chr == ',')
            coordinates.comma++;
    if (coordinates.comma != 1)
        return 0;
    for (auto chr : str)
        if (chr == '(')
            coordinates.l_bracket++;
    if (coordinates.l_bracket != 1)
        return 0;
    for (auto chr : str)
        if (chr == ')')
            coordinates.r_bracket++;
    if (coordinates.r_bracket != 1)
        return 0;
    if (str.find(' ') > str.find(','))
        return 0;

    strValues = str.substr(str.find('('), str.find(')'));
    for (auto chr : strValues)
        if (chr != ',' && chr != ' ' && !(chr >= '0' && chr <= '9')
            && chr != '(' && chr != ')' && chr != '.')
            return 0;

    if (strValues.length() <= 7)
        return 0;

    if ("circle" != str.substr(0, str.find_first_of("(")))
        return 0;
    return 1;
}

Calculations circle_compute(double radius)
{
    Calculations result;
    result.perimeter = 2 * 3.1415 * radius;
    result.area = 3.1415 * pow(radius, 2);

    return result;
}