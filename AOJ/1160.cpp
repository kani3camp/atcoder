//
// Created by kani3camp on 2024-10-10.
//


#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void dfs(const int count, const int x, const int y, vector<vector<int> >* c) {
    const int h = static_cast<int>(c->size());
    const int w = static_cast<int>(c->at(0).size());

    // 周囲の未割り当て-1マスを探索
    for (int i = max(0, x - 1); i <= min(h - 1, x + 1); i++) {
        for (int j = max(0, y - 1); j <= min(w - 1, y + 1); j++) {
            if ((*c)[i][j] == -1) {
                (*c)[i][j] = count;
                dfs(count, i, j, c);
            }
        }
    }
}

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        vector<vector<int> > c(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int c_i;
                cin >> c_i;
                if (c_i == 1) c_i = -1;
                c[i][j] = c_i;
            }
        }

        // 探索
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (c[i][j] == -1) {
                    c[i][j] = ++count;
                    // 周囲８マスを探索
                    dfs(count, i, j, &c);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}