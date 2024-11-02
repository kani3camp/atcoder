//
// Created by kani3camp on 2024-11-02.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int main() {
    long N; cin >> N;
    vector<long> A(N);
    map<long, long> max_i;
    for (long i = 0; i < N; i++) { cin >> A[i]; }

    for (long j = 0; j < N; j++) {
        long B;
        auto it = max_i.find(A[j]);
        if (it == max_i.end()) {
            B = -1;
        } else {
            B = it->second + 1;
        }
        cout << B << " ";
        max_i[A[j]] = j;
    }

    cout << endl;
    return 0;
}