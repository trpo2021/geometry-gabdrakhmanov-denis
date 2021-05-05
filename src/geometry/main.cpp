#include <cstring>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Circle {
    double x;
    double y;
    double r;
    int l_bracket = 0;
    int r_bracket = 0;
    int space = 0;
    int comma = 0;
};

struct Calculations {
    double perimeter;
    double area;
};

Calculations circle_compute(double radius)
{
    Calculations result;
    result.perimeter = 2 * 3.1415 * radius;
    result.area = 3.1415 * pow(radius, 2);

    return result;
}

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

int main()
{
    cout << "\x1B[2J\x1B[H";
    char figur[25];
    cout << "Enter figure: ";
    scanf("%[^\n]s", figur);
    int length = strlen(figur);
    string str = "";
    for (int i = 0; i < length; i++)
        str += figur[i];
    int flag = wkt_check(str);
    if (flag == 1) {
        Circle coordinates;
        coordinates.x = atof(str.substr(str.find_first_of("(") + 1,
                                        str.find_first_of(' ') - 1)
                                     .c_str());
        coordinates.x = atof(str.substr(str.find_first_of(' ') + 1,
                                        str.find_first_of(",") - 1)
                                     .c_str());
        coordinates.r = atof(str.substr(str.find_first_of(",") + 1,
                                        str.find_last_of(")") - 1)
                                     .c_str());
        Calculations result;
        result = circle_compute(coordinates.r);
        cout << str << endl;
        cout << "P = " << result.perimeter << endl;
        cout << "S = " << result.area << endl;
    } else
        cout << endl << "Error: wkt-format violated" << endl;
    return 0;
}