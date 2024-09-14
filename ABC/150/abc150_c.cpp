//
// Created by kani3camp on 2024/09/14.
//


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int P[N], Q[N];
    string p_str, q_str;
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        p_str += to_string(P[i]);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> Q[i];
        q_str += to_string(Q[i]);
    }

    string order;
    for (int i = 0; i < N; i++)
    {
        order += to_string(i + 1);
    }
    int count = 0;
    int p_i = 0, q_i = 0;
    do
    {
        if (p_str == order) p_i = count;
        if (q_str == order) q_i = count;
        count++;
    }
    while (next_permutation(order.begin(), order.end()));

    cout << abs(p_i - q_i) << endl;

    return 0;
}
