//
// Created by kani3camp on 2024-10-19.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

long N, M;
vector<vector<long> > g;
long min_depth = LONG_MAX;
vector<bool> visited;

void dfs(long current, long start, long depth) {
    if (current != start) visited[current] = true;
    for (long g_child : g[current]) {
        if (visited[g_child]) continue;
        if (g_child == start && depth + 1 < min_depth) {
            min_depth = depth + 1;
            return;
        }
        dfs(g_child, start, depth + 1);
    }
    visited[current] = false;
}

int main() {
    cin >> N >> M;
    g.resize(N);
    visited.resize(N, false);
    for (long i = 0; i < M; i++) {
        long a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    dfs(0, 0, 0);

    if (min_depth == LONG_MAX) min_depth = -1;
    cout << min_depth << endl;

    return 0;
}