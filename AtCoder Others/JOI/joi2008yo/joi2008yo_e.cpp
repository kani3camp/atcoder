//
// Created by kani3camp on 2024-09-13.
//


#include <iostream>
#include <cassert>
#include <algorithm>
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
    const int R_threshold = R / 2;
    const long p = pow(2, R);
    for (int bit = 0; bit < p; bit++) {   // Rについてビット全探索
        long ok = 0;    // 出荷可能な数
        for (int j = 0; j < C; j++)
        {
            int col_sum = 0;
            for (int i =0; i < R; i++) {
                auto row_hit = (1 << i & bit) > 0;
                bool that = a[i][j];
                if (row_hit) that = !that;
                col_sum += that;
            }
            if (col_sum > R_threshold) ok += col_sum;
            else ok += (R - col_sum);
        }
        if (ok > max_ok) {
            max_ok = ok;
        }
    }

    cout << max_ok << endl;

    return 0;
}