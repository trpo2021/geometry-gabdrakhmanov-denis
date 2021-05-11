#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circle_compute.h"
#include "wkt_check.h"

using namespace std;

int main()
{
    cout << "\x1B[2J\x1B[H";
    char _char[25];
    cout << "Enter figure: ";
    scanf("%[^\n]s", _char);
    int length = strlen(_char);
    string str = "";
    for (int i = 0; i < length; i++) {
        str += _char[i];
    }

    int check_flag = wkt_check(str);
    if (check_flag == 1) {
        Circle tokens;

        tokens.x = atof(str.substr(str.find_first_of("(") + 1,
                                   str.find_first_of(' ') - 1)
                                .c_str());
        tokens.x = atof(str.substr(str.find_first_of(' ') + 1,
                                   str.find_first_of(",") - 1)
                                .c_str());
        tokens.r = atof(str.substr(str.find_first_of(",") + 1,
                                   str.find_last_of(")") - 1)
                                .c_str());

        Calculations result_calc;
        result_calc = circle_compute(tokens.r);

        cout << str << endl;
        cout << "P = " << result_calc.perimeter << endl;
        cout << "S = " << result_calc.area << endl;
    } else {
        cout << "\nError: wkt-format violated" << endl;
    }
    return 0;
}