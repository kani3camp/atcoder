//
// Created by kani3camp on 2024/11/05.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
#include <numeric>

using namespace std;

int main()
{
    int D, N; cin >> D >> N;
    vector<int> T(D), A(N), B(N), C(N);
    for (int i = 0; i < D; i++) cin >> T[i];
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];

    vector dp = vector(D, vector<long>(N, 0));

    for (int day = 1; day < D; day++) {
        for (int n = 0; n < N; n++) {
            if (A[n] > T[day] || B[n] < T[day]) continue;

            long max = 0;
            for (int prev = 0; prev < N; prev++) {
                if (A[prev] > T[day-1] || B[prev] < T[day-1]) continue;

                auto point = dp[day-1][prev] + abs(C[n] - C[prev]);
                if (point > max) max = point;
            }
            dp[day][n] = max;
        }
    }

    cout << *max_element(dp[D-1].begin(), dp[D-1].end()) << endl;

    return 0;
}