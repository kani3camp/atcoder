//
// Created by kani3camp on 2024/11/03.
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

constexpr long long MOD = 10000;

int main()
{
    int N, K; cin >> N >> K;
    vector<int> reserved(N, -1);
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        reserved[a-1] = b-1;
    }

    vector<vector<long long> > dp(N+1, vector<long long>(3, 0));

    for (int n = 1; n <= N; n++)
    {
        if (reserved[n-1] == -1)    // 予約なし
        {
            if (n == 1)
            {
                dp[n][0] = 1;
                dp[n][1] = 1;
                dp[n][2] = 1;
            } else
            {
                // 前日または前々日が同じメニューが0であれば、前日の数を合計でOK
                // そうでなければ、（前日に別のメニューの数）＋（前々日に別のメニュー（かつ前日に同じメニュー）の数）
                for (int i = 0; i < 3; i++)
                {
                    if (dp[n-1][i] == 0 || dp[n-2][i] == 0)
                        dp[n][i] = accumulate(dp[n-1].begin(), dp[n-1].end(), 0LL);
                    else {
                        for (int j = 0; j < 3; j++) {
                            if (j == i) continue;
                            dp[n][i] += dp[n-1][j];
                            dp[n][i] += dp[n-2][j];
                        }
                    }
                    dp[n][i] %= MOD;
                }
            }
        } else  // 予約あり
        {
            auto selected = reserved[n-1];
            if (n == 1)
            {
                dp[n][selected] = 1;
            } else
            {
                if (dp[n-1][selected] == 0 || dp[n-2][selected] == 0)
                    dp[n][selected] = accumulate(dp[n-1].begin(), dp[n-1].end(), 0LL);
                else {
                    for (int j = 0; j < 3; j++) {
                        if (j == selected) continue;
                        dp[n][selected] += dp[n-1][j];
                        dp[n][selected] += dp[n-2][j];
                    }
                }
            }
            dp[n][selected] %= MOD;
        }
    }

    // 最終日の３択の合計
    auto sum = dp[N][0] + dp[N][1] + dp[N][2];
    auto ans = sum % MOD;
    cout << ans << endl;

    return 0;
}