#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// Define structures
struct Circle {
    double r;
    int x;
    int y;
    int space;
    int comma;
    int open_bracket;
    int close_bracket;
};
struct Calculations {
    double perimeter;
    double area;
};

// Define functions
Calculations circle_compute(char* circle, double radius);
int radius_check(char* figure, int indx1, int indx2);
int point_check(char* figure, int indx1, int indx2);
int control_count(int normal_value, int get_count);
Circle circle_wkt_check(char* figure, int circle_length);
int wkt_check(char* figure, int length);

int main()
{
    char obj[25];
    cout << "Enter figure: ";
    scanf("%[^\n]s", obj);
    int obj_length = strlen(obj);

    int check_flag = wkt_check(obj, obj_length);
    if (check_flag == 1) {
        Circle tokens;
        tokens = circle_wkt_check(obj, obj_length);

        Calculations result_calc;
        result_calc = circle_compute(obj, tokens.r);

        cout << obj << endl;
        cout << "P = " << result_calc.perimeter << endl;
        cout << "S = " << result_calc.area << endl;
    }
    return 0;
}

int wkt_check(char* figure, int length)
{
    int i, n;
    char example_circle[] = "circle(x y, r)";

    for (i = 0; (figure[i] != '(') && (i < length); ++i) {
        n = i;
    }
    if (n == 5) {
        for (i = 0; i < n; ++i) {
            if ((figure[i]) != example_circle[i]) {
                cout << "Error at column" << i << ": expected 'circle'" << endl;
                exit(EXIT_FAILURE);
            } else {
                figure[i] = (figure[i]);
                continue;
            }
        }
        return 1;
    } else {
        cout << "Error at column" << n + 1 << ": expected 'circle'" << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}

Circle circle_wkt_check(char* figure, int circle_length)
{
    Circle tokens;
    int i, tmp1, tmp2, tmp3, tmp4;
    tmp1 = tmp2 = tmp3 = tmp4 = 0;

    for (i = 0; i < circle_length; ++i) {
        if (figure[i] == '(') {
            tokens.open_bracket = i;
            tmp1++;
        }
        if ((figure[i] == ' ') && (isdigit(figure[i - 1]) != 0)) {
            tokens.space = i;
            tmp2++;
        }
        if (figure[i] == ',') {
            tokens.comma = i;
            tmp3++;
        }
        if (figure[i] == ')') {
            tokens.close_bracket = i;
            tmp4++;
        }
    }
    int cntrlcount = control_count(1, tmp1) + control_count(1, tmp2)
            + control_count(1, tmp3) + control_count(1, tmp4);
    if (cntrlcount != 4) {
        cout << "Error: unexpected token" << endl;
        exit(EXIT_FAILURE);
    } else {
        if (figure[tokens.close_bracket + 1] != '\0') {
            cout << "Error at column" << tokens.close_bracket + 1
                 << ": unexpected token" << endl;
            exit(EXIT_FAILURE);
        }
        int checker = point_check(figure, tokens.open_bracket, tokens.space);
        if (checker != 0) {
            int j = 0;
            char* coordX = new char[tokens.space - tokens.open_bracket];
            for (i = tokens.open_bracket + 1; i < tokens.space; ++i) {
                coordX[j] = figure[i];
                j++;
            }
            tokens.x = atoi(coordX);

            checker = point_check(figure, tokens.space, tokens.comma);
            if (checker != 0) {
                j = 0;
                char* coordY = new char[tokens.comma - tokens.space];
                for (i = tokens.space; i < tokens.comma; ++i) {
                    coordY[j] = figure[i];
                    j++;
                }
                tokens.y = atoi(coordY);

                checker = radius_check(
                        figure, tokens.comma, tokens.close_bracket);
                if (checker != 0) {
                    j = 0;
                    char* rad = new char[tokens.close_bracket - tokens.comma];
                    for (i = tokens.comma + 1; i < tokens.close_bracket; ++i) {
                        rad[j] = figure[i];
                        j++;
                    }
                    tokens.r = atof(rad);
                }
            }
        }
    }
    return tokens;
}

int control_count(int normal_value, int get_count)
{
    if (normal_value == get_count) {
        return 1;
    } else {
        return 0;
    }
}

int point_check(char* figure, int indx1, int indx2)
{
    int i;
    int checker = 0;
    for (i = indx1 + 1; i < indx2; ++i) {
        if (isdigit(figure[i]) != 0) {
            checker = 1;
        } else if (
                (figure[i] == ' ')
                || (((figure[i] == '+') || (figure[i] == '-'))
                    && (isdigit(figure[i + 1]) != 0))) {
            continue;
        } else {
            cout << "Error at column" << i << ": expected '<int>'" << endl;
            exit(EXIT_FAILURE);
        }
    }
    return checker;
}

int radius_check(char* figure, int indx1, int indx2)
{
    int i;
    int checker = 0;
    for (i = indx1 + 1; i < indx2; ++i) {
        if (isdigit(figure[i]) != 0) {
            checker = 1;
        } else if (
                (figure[i] == ' ')
                || (((figure[i] == '+') || (figure[i] == '.'))
                    && (isdigit(figure[i + 1]) != 0)
                    && (isdigit(figure[i - 1]) != 0))) {
            continue;
        } else {
            cout << "Error at column" << i << ": expected positive '<double>'"
                 << endl;
            exit(EXIT_FAILURE);
        }
    }
    return checker;
}

Calculations circle_compute(char* circle, double radius)
{
    Calculations result;
    result.perimeter = 2 * 3.1415 * radius;
    result.area = 3.1415 * pow(radius, 2);

    return result;
}