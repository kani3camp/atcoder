//
// Created by kani3camp on 2024/09/14.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    long long a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    if (N == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int first = 0; // 最初に見えないインデックス初期化。0はありえない
    long long tallest = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > tallest) tallest = a[i];
        else
        {
            first = i;
            break;
        }
    }
    if (first == 0 || K <= first + 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int remaining = K - first;

    // 最終的に見えるであろうfirst以降の組み合わせ
    string bitmask(remaining, '1');
    bitmask += string(N - remaining - first, '0');
    sort(bitmask.begin(), bitmask.end());

    long long min_cost = LONG_LONG_MAX;
    do
    {
        tallest = a[first - 1];
        long long cost = 0;
        for (int i = first; i < N; i++)
        {
            if (a[i] > tallest)
            {
                tallest = a[i];
                continue;
            }
            if (bitmask[i - first] == '1')
            {
                cost += tallest - a[i] + 1;
                tallest = tallest + 1;
            }
        }
        if (cost < min_cost) min_cost = cost;
    }
    while (next_permutation(bitmask.begin(), bitmask.end()));

    cout << min_cost << endl;

    return 0;
}
