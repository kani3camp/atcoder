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
    vector<int> A_vec(4, 0);
    for (int i = 0; i < 4; i++) {
        int A; cin >> A;
        A_vec[A - 1]++;
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += A_vec[i] / 2;
    }
    cout << ans << endl;

    return 0;
}
