//
// Created by kani3camp on 2024-11-02.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
#include <queue>
using namespace std;

int H, W, K;
vector<vector<bool> > S(H, vector<bool>(W));
vector<vector<bool> > visited;
long sum = 0;
// 上下左右
vector<int> path_i = {-1, 0, 1, 0};
vector<int> path_j = {0, 1, 0, -1};

int depth_of_visited() {
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j]) ans++;
        }
    }
    return ans;
}

void dfs(pair<int, int> p) {
    visited[p.first][p.second] = true;
    if (depth_of_visited() == K + 1) {
        sum++;
    } else {
        // 次に移動する隣のマス
        for (int n = 0; n < 4; n++) {
            int i = p.first + path_i[n];
            int j = p.second + path_j[n];

            // はみ出てないか
            if (i < 0 || j < 0 || i >= H || j >= W) continue;

            // 障害物マスか
            if (!S[i][j]) continue;

            // すでに訪問済みでないか
            if (visited[i][j]) continue;

            dfs(make_pair(i, j));
        }
    }
    visited[p.first][p.second] = false;
}


int main() {
    cin >> H >> W >> K;
    // 入力、Sの初期化
    S.assign(H, vector<bool>(W, false));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char s; cin >> s;
            if (s == '.') S[i][j] = true;
            else S[i][j] = false;
        }
    }
    // visitedの初期化
    visited.assign(H, vector<bool>(W, false));

    // 深さ優先探索
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j]) {
                dfs(make_pair(i, j));
            }
        }
    }

    cout << sum << endl;

    return 0;
}