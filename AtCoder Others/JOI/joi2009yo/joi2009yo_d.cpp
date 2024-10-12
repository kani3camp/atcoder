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
#include <utility>

using namespace std;

int m, n;
vector<vector<int> > c;

unsigned long dfs(int i, int j, unsigned long max_depth, vector<pair<int, int> >* parent_stack)
{
    parent_stack->push_back(pair<int, int>(i, j));
    if (parent_stack->size() > max_depth) max_depth = parent_stack->size();

    for (int h = max(0, i - 1); h <= min(n-1, i + 1); h++)
    {
        for (int w = max(0, j - 1); w <= min(m-1, j + 1); w++)
        {
            if (c[h][w] == 0) continue;
            if (h != i && w != j) continue; // 斜めは飛ばす
            pair<int, int> current(h, w);
            if (any_of(parent_stack->begin(), parent_stack->end(), [current](pair<int, int>& p) { return p == current; })) continue;
            auto tmp_depth = dfs(h , w, max_depth, parent_stack);
            if (tmp_depth > max_depth) max_depth = tmp_depth;
        }
    }
    parent_stack->pop_back();
    return max_depth;
}

int main()
{
    cin >> m >> n;
    c.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            c[i].push_back(a);
        }
    }

    unsigned long max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] == 0) continue;
            vector<pair<int, int> > parent_stack;
            auto count = dfs(i, j, 0, &parent_stack);
            if (count > max) max = count;
        }
    }

    cout << max << endl;

    return 0;
}
