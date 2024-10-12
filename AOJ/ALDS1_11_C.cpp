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
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<vector<int > > v(n);
    for (int i = 0; i < n; i++)
    {
        int u, k;
        cin>>u>>k;
        u--;
        for (int j = 0; j < k; j++)
        {
            int v_value;
            cin >> v_value;
            v_value--;
            v[u].push_back(v_value);
        }
    }

    vector<int> d(n, -1);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        for (auto next : v[pos])
        {
            if (d[next] == -1)
            {
                d[next] = d[pos] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i+1 << " " << d[i] << endl;
    }

    return 0;
}