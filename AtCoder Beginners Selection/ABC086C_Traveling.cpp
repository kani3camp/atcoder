//
// Created by kani3camp on 2024-09-08.
// 解説みてから
//
#include <iostream>
using namespace std;



int main() {
    long N;
    cin >> N;

    long t[N];
    long x[N];
    long y[N];
    for (long i = 0; i < N; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    if (N == 1) {
        auto d = x[0] + y[0];
        auto dt = t[0];
        if (d > dt) {
            cout << "No" << endl;
            return 0;
        }
        if ((dt - d) % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        return 0;
    }

    for (long i = 1; i < N; i++) {
        auto d = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);    // マンハッタン距離
        auto dt = t[i] - t[i - 1];
        if (d > dt) {
            cout << "No" << endl;
            return 0;
        }
        if ((dt - d) % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
