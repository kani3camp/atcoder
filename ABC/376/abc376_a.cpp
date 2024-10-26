//
// Created by kani3camp on 2024-10-19.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> T(N); for (int i = 0; i < N; i++) cin >> T[i];

    int sum = 1;
    int prev = T[0];
    for (int i = 1; i < N; i++) {
        if (T[i] - prev >= C) {
            sum++;
            prev = T[i];
        }
    }
    cout << sum << endl;

    return 0;
}