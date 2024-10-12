//
// Created by kani3camp on 2024-10-12.
//


#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int N, Q;
vector<vector<int> > tree;
vector<int> counter;

void dfs(int n, int x) {
    counter[n] += x;
    for (int i = 0; i < tree[n].size(); i++) {
        dfs(tree[n][i], x);
    }
}

int main() {
    cin >> N >> Q;
    vector<int> a(N-1), b(N-1);
    for (int i = 0; i < N - 1; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> p(Q), x(Q);
    for (int i = 0; i < Q; i++) {
        cin >> p[i] >> x[i];
    }
    counter.resize(N);
    tree.resize(N);
    for (int i = 0; i < N - 1; i++) {
        tree[a[i] - 1].push_back(b[i] - 1);
    }

    for (int i = 0; i < Q; i++) {
        int n = p[i] - 1;
        dfs(n, x[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << counter[i] << " ";
    }
    return 0;
}