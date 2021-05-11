#pragma once
#ifndef LIB_CIRCLE_H
#define LIB_CIRCLE_H
#include <string>
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

bool wkt_check(string str);
Calculations circle_compute(double radius);
#endif