//
// Created by kani3camp on 2024-09-13.
//


#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

long pow(int base, int exp) {
    long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    int x[M], y[M];
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
    }

    int max = 0;

    for (int i = 0; i < pow(2, N); i++) {
        // 選ばれた人をリストアップして、組み合わせを全探索
        vector<int> selectee;
        for (int bit = 0; bit < N; bit++) {
            if ((1 << bit) & i) selectee.push_back(bit);
        }
        sort(selectee.begin(), selectee.end()); // pushの順番的にすでに昇順かも？
        if (selectee.size() == 0) continue;

        bool go_next = false;
        for (int j1 = 0; j1 < selectee.size() - 1; j1++) {
            for (int j2= j1 + 1; j2 < selectee.size(); j2++) {
                bool related = false;
                for (int k = 0; k < M; k++) {
                    if (x[k] == (selectee[j1] + 1) && y[k] == (selectee[j2] + 1)) {
                        related = true;
                        break;
                    }
                }
                if (!related) {
                    go_next = true;
                }
            }
            if (go_next) break;
        }
        if (!go_next) {
            if (max < selectee.size()) max = selectee.size();
        }
    }

    cout << max << endl;

    return 0;
}