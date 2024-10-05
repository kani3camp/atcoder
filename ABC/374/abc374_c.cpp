//
// Created by kani3camp on 2024-10-05.
//


#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    long K[N];
    for (int i = 0; i < N; i++) cin >> K[i];

    long min_bigger = LONG_MAX;   // answer
    for (int n = 1; n <= N / 2 + 1; n++) {
        // 組み合わせ全探索 N個からn個選んでAとし、それ以外をB
        string bit;
        for (int i = 0; i < n; i++) bit += '1';
        for (int i = 0; i < N - n; i++) bit += '0';
        sort(bit.begin(), bit.end());

        do {
            long sum0 = 0, sum1 = 0;
            for (int i = 0; i < N; i++) {
                if (bit[i] == '1') sum1 += K[i];
                if (bit[i] == '0') sum0 += K[i];
            }
            long bigger = max(sum0, sum1);
            if (min_bigger > bigger) min_bigger = bigger;
        } while (next_permutation(bit.begin(), bit.end()));
    }
    cout << min_bigger << endl;

    return 0;
}