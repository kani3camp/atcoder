//
// Created by kani3camp on 2024-10-12.
//


#include <iostream>
#include <cassert>
#include <set>
#include <vector>
using namespace std;

int N, Q;
vector<vector<int> > tree;
vector<set<int> > subtree;
vector<long> counter;

set<int> dfs(int n)
{
    set<int> children;
    for (int child : tree[n])
    {
        children.insert(child);
        auto c = dfs(child);
        children.insert(c.begin(), c.end());
    }
    return children;
}

int main()
{
    cin >> N >> Q;
    vector<int> a(N - 1), b(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<int> p(Q), x(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> p[i] >> x[i];
    }

    counter.resize(N);
    tree.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        tree[a[i] - 1].push_back(b[i] - 1);
    }

    // sbtreeの構築：その頂点のすべての子孫を格納する
    subtree.resize(N);
    for (int i = 0; i < N; i++)
    {
        auto children = dfs(i);
        subtree[i].insert(children.begin(), children.end());
    }

    for (int i = 0; i < Q; i++)
    {
        int n = p[i] - 1;
        counter[n] += x[i];
        for (int j : subtree[n])
            counter[j] += x[i];
    }

    for (int i = 0; i < N; i++)
    {
        cout << counter[i] << " ";
    }
    return 0;
}
