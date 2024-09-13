//
// Created by kani3camp on 2024-09-13.
//


#include <iostream>
#include <cassert>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long A[N], B[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // A -> B
    long long sum_AB = 0;
    for (int i = 0; i < N; i++) {
        sum_AB += B[i] - A[i];
    }

    // in -> A
    multiset<long long> aset;
    for (int i = 0; i < N; i++) {
        aset.insert(A[i]);
    }
    int median_A_i = aset.size() / 2;
    long long median_A = *next(aset.begin(), median_A_i);

    long long sum_A = 0;
    for (int n = 0; n < N; n++) {
        sum_A += abs(A[n] - median_A);
    }

    // B -> out
    multiset<long long> bset;
    for (int i = 0; i < N; i++) {
        bset.insert(B[i]);
    }
    int median_B_i = bset.size() / 2;
    long long median_B = *next(bset.begin(), median_B_i);

    long long sum_B = 0;
    for (int n = 0; n < N; n++) {
        sum_B += abs(B[n] - median_B);
    }

    cout << sum_AB + sum_A + sum_B << endl;

    return 0;
}