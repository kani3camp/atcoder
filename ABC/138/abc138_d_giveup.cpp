//
// Created by kani3camp on 2024/10/12.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector< int > > adj;    // 隣接リスト
vector<int> counter;

void dfs(int current, int parent = -1)
{
    for (auto v : adj[current])
    {
        if (v != parent)
        {
            counter[v] += counter[current];
            dfs(v, current);
        }
    }
}

int main()
{
    int N, Q;
    cin>>N>>Q;

    adj.resize(N);
    counter.resize(N);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < Q; i++)
    {
        int p, x;
        cin>>p>>x;
        p--;
        counter[p] += x;
    }

    dfs(0);

    for (int i = 0; i < N; i++)  cout<<counter[i]<<" ";
    return 0;
}