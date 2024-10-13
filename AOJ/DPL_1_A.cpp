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
    int n , m; cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) cin >> c[i];

    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < m; i++) {
        for (int price = c[i]; price <= n; price++) {
            if (price == c[i]) {
                dp[price - 1] = 1;
            } else {
                if (price - c[i] > 0) {
                    dp[price - 1] = min(dp[price - 1], dp[price - c[i] - 1] + 1);
                }
            }
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}