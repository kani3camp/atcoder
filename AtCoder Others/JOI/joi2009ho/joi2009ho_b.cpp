//
// Created by kani3camp on 2024/09/23.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int d, n, m;
    cin >> d >> n >> m;

    int d_arr[n - 1];
    int k_arr[m];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> d_arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> k_arr[i];
    }

    sort(d_arr, d_arr + n - 1);

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int k = k_arr[i];

        int L = 0;
        int R = n - 2;
        if (d_arr[R] < k)
        {
            sum += min(d - k, k - d_arr[R]);
            continue;
        }
        if (d_arr[L] > k)
        {
            sum += min(d_arr[L] - k, k);
            continue;
        }
        while (L <= R)
        {
            if (L + 1 == R)
            {
                sum += min(d_arr[R] - k, k - d_arr[L]);
                break;
            }
            int M = (L + R) / 2;
            if (d_arr[M] < k)
            {
                L = M;
            }
            if (d_arr[M] == k)
            {
                break;
            }
            if (d_arr[M] > k)
            {
                R = M;
            }
        }
    }
    cout << sum << endl;

    return 0;
}
