//
// Created by kani3camp on 2024-09-27.
//


#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    long double P;
    cin >> P;

    long double x = -1.5 / log(2) * log(1.5 / log(2) / P);
    long double calc_time = P * pow(2, -x / 1.5);

    if (x < 0) {
        cout << fixed << setprecision(8) << P << endl;
    } else {
        cout << fixed << setprecision(8) << x + calc_time << endl;
    }

    return 0;
}
