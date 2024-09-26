//
// Created by kani3camp on 2024-09-26.
//


#include <algorithm>
#include <iostream>
#include <cassert>
#include <set>
#include <vector>
#include <climits>
using namespace std;

int main() {
    long N;
    cin >> N;

    long long H[N], S[N];
    for (long i = 0; i < N; i++) {
        cin >> H[i] >> S[i];
    }

    long long min_height = LONG_LONG_MAX;
    long long L = 1;
    long long R = LONG_LONG_MAX;
    while (L <= R) {
        long long M = (L + R) / 2;
        // 高さM以下に抑えられるか
        bool ok = true;
        vector<long long> rem(N, 0); // 制限時間
        for (long i = 0; i < N; i++) {
            if (H[i] > M) ok = false;
            else rem[i] = (M - H[i]) / S[i];
        }
        sort(rem.begin(), rem.end());
        long t = 0;
        for (long i = 0; i < N; i++) {
            if (t > rem[i]) {
                ok = false;
                break;
            }
            t++;
        }
        if (ok) {
            if (min_height > M) min_height = M;
            R = M - 1;
        } else {
            L = M + 1;
        }
    }

    cout << min_height << endl;

    return 0;
}
