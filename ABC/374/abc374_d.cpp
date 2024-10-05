//
// Created by kani3camp on 2024-10-05.
//


#include <algorithm>
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <climits>
#include <float.h>
#include <iomanip>
using namespace std;

double distance(int a, int b, int c, int d) {
    return sqrt(abs(a - c) * abs(a - c) + abs(b - d) * abs(b - d));
}

int main() {
    int N, S, T;
    cin >> N >> S >> T;

    int A[N], B[N], C[N], D[N];
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 各線分を描く時間は求めておく
    double sum_t_line = 0;
    for (int i = 0; i < N; i++) {
        double d = distance(A[i], B[i], C[i], D[i]);
        sum_t_line += d / T;
    }

    vector<int> i_perm;
    i_perm.reserve(N);
    for (int i = 0; i < N; i++) i_perm.push_back(i);
    auto min_sum_t_move = DBL_MAX;
    do {
        // 順列全探索：線分の描く順番
        // ビット全探索：各線分をどちらの方向から描くか
        for (int bit = 0; bit < pow(2, N); bit++) {
            // 時間計算 （レーザー照射時間は除く）
            double sum_t_move = 0;
            for (int i = 0; i < N; i++) {
                int a, b, c, d;
                if (i == 0) {
                    // 0の座標(a, b)
                    a = 0, b = 0;
                    // iの座標(c, d)
                    if (bit & (1 << i)) c = C[i_perm[i]], d = D[i_perm[i]];
                    else c = A[i_perm[i]], d = B[i_perm[i]];
                } else {
                    // i-1の座標(a, b)
                    if (bit & (1 << (i - 1))) a = A[i_perm[i-1]], b = B[i_perm[i-1]];
                    else a = C[i_perm[i-1]], b = D[i_perm[i-1]];
                    // iの座標(c, d)
                    if (bit & (1 << i)) c = C[i_perm[i]], d = D[i_perm[i]];
                    else c = A[i_perm[i]], d = B[i_perm[i]];
                }
                sum_t_move += distance(a, b, c, d) / S;
            }
            if (sum_t_move < min_sum_t_move) min_sum_t_move = sum_t_move;
        }
    } while (next_permutation(i_perm.begin(), i_perm.end()));

    cout << fixed << setprecision(8) << (sum_t_line + min_sum_t_move) << endl;

    return 0;
}
