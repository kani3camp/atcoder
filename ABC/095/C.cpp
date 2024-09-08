//
// Created by kani3camp on 2024-09-08.
//
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    long X, Y;

    cin >> A >> B >> C >> X >> Y;

    long long total = 0;

    if (C > A && C > B) {
        total = A * X + B * Y;
    } else if (C < A && C < B) {
        total = 2 * C * min(X, Y);
        if (X > Y) {
            if (A >= 2 * C) {
                total += (X-Y) * 2 * C;
            } else {
                total += (X-Y) * A;
            }
        } else if (Y > X) {
            if (B >= 2 * C) {
                total += (Y-X) * 2 * C;
            } else {
                total += (Y-X) * B;
            }
        }
    } else {
        // 全探索
        long long min_total = 2 * 5000 * 100000;  // 想定される最大値を初期値とする
        for (int i = 0; i <= max(X, Y); i++) {
            long long sum = 2 * C * i;
            sum += A * max(0l, X - i);
            sum += B * max(0l, Y - i);
            if (sum < min_total) {
                min_total = sum;
            }
        }
        total = min_total;
    }
    cout << total;
    return 0;
}