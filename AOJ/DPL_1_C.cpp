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

    vector< vector<int> > dp(N + 1, vector<int>(W + 1, 0));
    for (int n = 1; n <= N; n++)
    {
        for (int w_limit = 1; w_limit <= W; w_limit++)
        {
            int select;
            if (w[n-1] > w_limit)
            {
                if (n == 1)
                {
                    select = 0;
                } else
                {
                    select = dp[n-1][w_limit];
                }
            } else
            {
                int max_v = 0;
                for (int i = 1; i <= w_limit / w[n-1]; i++)
                {
                    int val;
                    if (n == 1)
                    {
                        val = i * v[n-1];
                    } else
                    {
                        val = dp[n-1 - 1][w_limit - i*w[n-1]] + i*v[n-1];
                    }
                    max_v = max(max_v, val);
                }
                select = max_v;
            }

            int not_select;
            if (n == 1)
            {
                not_select = 0;
            } else
            {
                not_select = dp[n-1-1][w_limit];
            }

            dp[n-1][w_limit] = max(select, not_select);
        }
    }

    cout << dp[N-1][W] << endl;
    return 0;
}