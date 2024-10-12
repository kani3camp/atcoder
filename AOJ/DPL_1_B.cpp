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
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

    vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));
    for (int n = 1; n <= N; n++) {
        for (int w_limit = 0; w_limit <= W; w_limit++) {
            // それを選ぶ場合
            int select;
            int prev_w = w_limit - w[n - 1];
            if (prev_w >= 0) {
                select = v[n - 1] + dp[n - 1][prev_w];
            } else {
                select = 0;
            }

            // それを選ばない場合
            int not_select;
            if (n >= 2) {
                not_select = dp[n - 1][w_limit];
            } else {
                not_select = 0;
            }

            dp[n][w_limit] = max(select, not_select);
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}