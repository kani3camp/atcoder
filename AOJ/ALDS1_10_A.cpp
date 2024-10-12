//
// Created by kani3camp on 2024/10/12.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> sum(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0) sum[i] = 1;
        else if (i == 1) sum[i] = 1;
        else
        {
            sum[i] = sum[i - 1] + sum[i - 2];
        }
    }
    cout << sum[n] << endl;
    return 0;
}