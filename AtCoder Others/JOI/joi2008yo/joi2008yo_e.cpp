//
// Created by kani3camp on 2024-09-13.
//


#include <iostream>
#include <cassert>
using namespace std;

long pow(int base , int exp) {
    long result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int R, C;
    cin >> R >> C;

    short a[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    long max_ok = 0;
    const long p = pow(2, R+C);
    for (int bit = 0; bit < p; bit++) {   // ビット全探索
        long ok = 0;    // 出荷可能な数
        for (int i =0; i < R; i++) {
            auto row = (1 << i) & bit;
            for (int j = 0; j < C; j++) {
                auto col = 1 << (j + R) & bit;
                if (row > 0 && col > 0) {
                    if (a[i][j] == 0) ok++;
                } else if (row > 0 || col > 0) {
                    if (a[i][j] == 1) ok++;
                } else {    // row = 0 && col = 0
                    if (a[i][j] == 0) ok++;
                }
            }
        }
        if (ok > max_ok) {
            max_ok = ok;
        }
    }

    cout << max_ok << endl;

    return 0;
}