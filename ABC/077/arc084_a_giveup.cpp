//
// Created by kani3camp on 2024/09/23.
//


#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int A[N], B[N], C[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    // sort
    sort(B, B + N);
    sort(C, C + N);

    // 前もってBの累積和を求めておく
    long cum_B[N];
    long cum = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        auto it_c = upper_bound(C, C + N, B[i]);
        cum += C + N - it_c;
        cum_B[i] = cum;
    }

    long sum = 0;
    for (int i = 0; i < N; i++)
    {
        auto it_b = upper_bound(B, B + N, A[i]);
        if (it_b != B + N)
        {
            auto dist = it_b - B;
            sum += cum_B[dist];
        }
    }

    cout << sum << endl;

    return 0;
}