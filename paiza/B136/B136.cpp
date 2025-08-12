//
// Created by 白坂潤 on 2025/08/13.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    int sy, sx;
    cin >> sy >> sx;

    string s;
    cin >> s;

    vector<vector<int> > c(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c[i][j];
        }
    }

    pair<int, int> current = make_pair(sx - 1, sy - 1);
    vector<int> got_list;
    for (char ch: s) {
        switch (ch) {
            case 'F':
                current = make_pair(current.first, current.second-1);
                break;
            case 'L':
                current = make_pair(current.first-1, current.second);
                break;
            case 'R':
                current = make_pair(current.first+1, current.second);
                break;
            case 'B':
                current = make_pair(current.first, current.second+1);
                break;
            default:
                break;
        }
        got_list.push_back(c[current.second][current.first]);
    }

    for (int got : got_list) {
        cout << got << endl;
    }

    return 0;
}
