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

    int A[N];
    multiset<int> B, C;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        B.insert(input);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        C.insert(input);
    }

    // 前もってBの累積和を求めておく
    long cum_B[N];
    int i = 0;
    for (auto it = B.begin(); it != B.end(); ++it)
    {
        auto it_c = C.upper_bound(*it);
        cum_B[i] = distance( it_c, C.end());
        i++;
    }

    long sum = 0;
    for (int i = 0; i < N; i++)
    {
        auto it_b = B.upper_bound(A[i]);
        sum += cum_B[distance(B.begin(), it_b)];
    }

    cout << sum << endl;

    return 0;
}