//
// Created by kani3camp on 2024-10-12.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    long double sum = 0;
    for (int i = 0; i <= N; i++) {
        long double dist;
        if (i == 0) {
            dist = sqrt(X[i] * X[i] + Y[i] * Y[i]);
        } else if (i == N) {    // 最後、原点に戻る
            dist = sqrt(X[i-1] * X[i-1] + Y[i-1] * Y[i-1]);
        } else {
            long long x = abs(X[i] - X[i-1]);
            long long y = abs(Y[i] - Y[i-1]);
            dist = sqrt(x * x + y * y);
        }
        sum += dist;
    }

    cout << fixed << setprecision(7) << sum << endl;

    return 0;
}