//
// Created by kani3camp on 2024/09/28.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int dfs(int x, int t, int d[109], int k[109], int v[][109], int f[109])
{
    for (int i = 0; i < k[x]; i++)
    {
        if (d[i] == 0) d[i] = t;
        else continue;
        t = dfs(v[x][i], t+1, d, k, v, f);
    }
    f[x] = t;
    return ++t;
}

int main()
{
    int n;
    int k[109];
    int v[109][109];
    int d[109] = {};
    int f[109];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            cin >> v[i][j];
        }
    }

    int t = 1;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 0) d[i] = t;
        else continue;
        t = dfs(i, t, d, k, v, f);
        t++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }
    return 0;
}