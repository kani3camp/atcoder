// //
// // Created by kani3camp on 2024/11/03.
// //
//
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
//
// using namespace std;
//
// int main()
// {
//     int q; cin >> q;
//
//     for (int i = 0; i < q; i++)
//     {
//         string X, Y; cin >> X >> Y;
//
//     }
//
//     return 0;
// }
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        int x_size = x.size() - 0;
        int y_size = y.size() - 0;
        vector<vector<int> > dp(x_size + 1, vector<int>(y_size + 1, 0));
        for (int i = 0; i < x_size; i++)
        {
            for (int j = 0; j < y_size; j++)
            {
                if (x[i] == y[j])
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                }
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
            }
        }
        cout << dp[x_size][y_size] << endl;
    }
    return 0;
}
