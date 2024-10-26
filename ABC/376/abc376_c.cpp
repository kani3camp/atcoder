//
// Created by kani3camp on 2024-10-19.
//


#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long> A(N), B(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long max_i = -1;    // １つ上のAより小さいBの最大インデックス
    for (int i = 0; i < N-1; i++) {
        if (B[i] < A[i]) {
            cout << -1 << endl; return 0;
        }
        if (B[i] < A[i+1]) max_i = i;
    }
    if (max_i == -1) {
        cout << A[0] << endl;
    } else {
        cout << A[max_i+1] << endl;
    }

    return 0;
}