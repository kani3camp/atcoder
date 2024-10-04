//
// Created by kani3camp on 2024/09/28.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dfs(long current_i, long current_x, vector<vector<vector<int> > >* adj, vector<long>* x)
{

}

int main()
{
    int N, M;
    cin >> N >> M;

    int u[M], v[M];
    long w[M];
    for (int i = 0; i < M; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    // 隣接リスト
    vector<vector<vector<int> > > adj(N, vector<vector<int> >(2, vector<int>())); // 入ってくる, 出ていく
    for (int i = 0; i < M; i++)
    {
        adj[v[i] - 1][0].push_back(u[i] - 1);   // vに入っていくu
        adj[u[i] - 1][1].push_back(v[i] - 1);   // uから出ていくv
    }

    // 深さ優先探索
    vector<long> x(N);
    long current_x = 0;
    long current_i = 0;
    while (true)
    {
        dfs(current_i, current_x, &adj, &x);
    }

    for (int i = 0; i < N; i++)
    {
        cout << x[i] << endl;
    }

    return 0;
}