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

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];

    vector<vector<long long>> dp(N - 1, vector<long long>(21, 0));
    dp[0][nums[0]] = 1;
    for (int i = 1; i < N - 1; i++)
    {
        int diff = nums[i];
        for (int num = 0; num <= 20; num++)
        {
            if (dp[i - 1][num] > 0)
            {
                // +diff
                if (num + diff <= 20)
                {
                    dp[i][num + diff] += dp[i - 1][num];
                }

                // -diff
                if (num - diff >= 0)
                {
                    dp[i][num - diff] += dp[i - 1][num];
                }
            }
        }
    }

    cout << dp[N - 2][nums[N - 1]] << endl;

    return 0;
}
