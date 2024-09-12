//
// Created by kani3camp on 2024-09-10.
//


#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

constexpr double ERR = 0.0000001;

// お互いの距離（の2乗）のセット
set<pair<long, pair<int, int> > > dists;
int n;
vector<int> x, y;

long pow(int base, int exp) {
    long result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;
    }
    return result;
}

long dist(int x1, int y1, int x2, int y2) {
    return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
}

bool is_square(const set<pair<int, int> > &eq_dists_set) {
    // vectorに変換
    const vector<pair<int, int> > eq_dists(eq_dists_set.begin(), eq_dists_set.end());
    // 隣接リスト
    map<int, set<int> > adj_map;
    for (auto it = eq_dists_set.begin(); it != eq_dists_set.end(); ++it) {
        adj_map[it->first].emplace(it->second);
        adj_map[it->second].emplace(it->first);
    }
    // 次数１の点は除外
    while (true) {
        bool found = false;
        for (auto it = adj_map.begin(); it != adj_map.end(); ) {
            if (it->second.size() == 1) {
                found = true;
                adj_map[*it->second.begin()].erase(it->first);
                it = adj_map.erase(it);
            } else {
                ++it;
            }
        }
        if (!found) break;
    }
    // 閉路を見つけ、正方形チェック
    vector<vector<int> > rectangle_points;
    for (const auto& [it1, value] : adj_map) {
        for (auto it2 = adj_map[it1].begin(); it2 != adj_map[it1].end(); ++it2) {
            for (auto it3 = adj_map[*it2].begin(); it3 != adj_map[*it2].end(); ++it3) {
                if (*it3 == it1) continue;
                for (auto it4 = adj_map[*it3].begin(); it4 != adj_map[*it3].end(); ++it4) {
                    if (*it4 == *it2 || *it4 == it1) continue;
                    for (auto it5 = adj_map[*it4].begin(); it5 != adj_map[*it4].end(); ++it5) {
                        if (*it5 == it1) {
                            // 四角形の閉路
                            vector<int> pts = {it1, *it2, *it3, *it4};
                            rectangle_points.emplace_back(pts);
                        }
                    }
                }
            }
        }
    }

    // 対角線の長さが等しければ正方形
    for (const auto it = rectangle_points.begin(); it != rectangle_points.end();) {
        const int p1 = (*it)[0];
        const int p2 = (*it)[1];
        const int p3 = (*it)[2];
        const int p4 = (*it)[3];

        const auto diagonal1 = pow(abs(x[p1] - x[p3]), 2) + pow(abs(y[p1] - y[p3]), 2);
        const auto diagonal2 = pow(abs(x[p2] - x[p4]), 2) + pow(abs(y[p2] - y[p4]), 2);

        if (diagonal1 == diagonal2) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x_i, y_i;
        cin >> x_i >> y_i;
        x.push_back(x_i);
        y.push_back(y_i);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            dists.emplace(dist(x[i], y[i], x[j], y[j]), make_pair(i, j));
        }
    }

    long current_dist = 0;
    set<pair<int, int> > points;
    for (auto it = dists.rbegin(); it != dists.rend(); ++it) {
        if (current_dist == 0) {
            // 最初だけは初期化
            current_dist = it->first;
        } else if (current_dist != it->first) {
            // 正方形チェック
            if (points.size() >= 4 && is_square(points)) {
                cout << current_dist << endl;
                return 0;
            };

            current_dist = it->first;
            points.clear();
            points.emplace(it->second.first, it->second.second);
        } else {
            points.emplace(it->second.first, it->second.second);
        }
    }
    // 最後の正方形チェック
    if (points.size() >= 4 && is_square(points)) {
        cout << current_dist << endl;
        return 0;
    };

    cout << 0 << endl;

    return 0;
}
