//
// Created by kani3camp on 2024/09/14.
//


#include <iostream>
#include <algorithm>
#include <complex>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int x[N], y[N];
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
    }

    string order_str;
    for (int i = 0; i < N; i++)
    {
        order_str += to_string(i);
    }

    double sum_dist = 0.0;
    int count = 0;
    do
    {
        double dist = 0.0;
        for (int i = 1; i < N; i++)
        {
            int prev_n = order_str[i - 1] - '0';    // intに変換
            int current_n = order_str[i] - '0';
            auto x_diff = abs(x[current_n] - x[prev_n]);
            auto y_diff = abs(y[current_n] - y[prev_n]);
            dist += sqrt(x_diff * x_diff + y_diff * y_diff);
        }
        sum_dist += dist;
        count++;
    }
    while (next_permutation(order_str.begin(), order_str.end()));

    cout << fixed << setprecision(6) << (sum_dist / count) << endl;

    return 0;
}
