//
// Created by kani3camp on 2024-11-02.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    long N; cin >> N;
    vector<long> q_list(N), r_list(N);
    for (long i = 0; i < N; i++) { cin >> q_list[i] >> r_list[i]; }
    long Q; cin >> Q;
    vector<long> t_list(Q), d_list(Q);
    for (long i = 0; i < Q; i++) { cin >> t_list[i] >> d_list[i]; }

    for (long j = 0; j < Q; j++) {
        const long t = t_list[j];
        const long first_day = d_list[j];
        const long q = q_list[t-1];
        const long r = r_list[t-1];
        long ans_1 = q * (first_day / q) + q + r;
        long ans_2 = ans_1 - q;
        if (ans_2 >= first_day) cout << ans_2 << endl;
        else cout << ans_1 << endl;
    }

    return 0;
}