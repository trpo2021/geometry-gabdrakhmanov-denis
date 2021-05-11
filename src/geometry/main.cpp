#include "lib_circle.h"
#include <cstring>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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