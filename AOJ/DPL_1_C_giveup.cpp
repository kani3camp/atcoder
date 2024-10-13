//
// Created by kani3camp on 2024-10-13.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N, W; cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

    vector<int> dp(W + 1 );
    for (int n = 0; n < N; n++) {
        for (int w_limit = 0; w_limit <= W; w_limit++) {
            if (w_limit + w[n] > W) continue;
            dp[w_limit + w[n]] = max(dp[w_limit + w[n]], dp[w_limit] + v[n]);
        }
    }
    int max_dp = 0;
    for (int i = 0; i < W+1; i++) max_dp = max(max_dp, dp[i]);
    cout << max_dp << endl;
    return 0;
}