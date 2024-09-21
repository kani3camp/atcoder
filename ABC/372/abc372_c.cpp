//
// Created by kani3camp on 2024-09-21.
//


#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;

    int X[Q];
    char C[Q];
    for (int i = 0; i < Q; i++) {
        cin >> X[i] >> C[i];
    }

    // まず累積和を求めておく
    int csum[N] = {0};
    for (int i = 0; i < N; i++) {
        if (i + 2 >= N) {
            csum[i] = csum[N - 3];
            continue;
        }
        if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
            if (i == 0) {
                csum[i] = 1;
            } else {
                csum[i] = csum[i - 1] + 1;
            }
        } else {
            if (i == 0) csum[i] = 0;
            else csum[i] = csum[i - 1];
        }
    }

    // 各クエリを処理
    for (int q = 0; q < Q; q++) {
        int x = X[q] - 1;

        // 置換位置中心の５文字
        S[x] = C[q];
        int min_i = max(x - 2, 0);
        int max_i = min(x + 2, N - 1);
        int before_csum_max_i = csum[max_i];
        for (int i = min_i; i <= max_i; i++) {
            if (i + 2 >= N) {
                csum[i] = csum[N - 3];
                continue;
            }
            if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
                if (i == 0) csum[i] = 1;
                else csum[i] = csum[i - 1] + 1;

            } else {
                if (i == 0) csum[i] = 0;
                else csum[i] = csum[i - 1];
            }
        }

        // 置換位置以降の累積和を更新
        int diff = csum[max_i] - before_csum_max_i;
        if (diff != 0 && x < N - 3) {
            for (int i = x + 3; i < N; i++) {
                csum[i] = csum[i] + diff;
            }
        }

        cout << csum[N-1] << endl;

    }

    return 0;
}
