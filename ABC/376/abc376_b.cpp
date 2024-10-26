//
// Created by kani3camp on 2024-10-19.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<char> H(Q);
    vector<int> T(Q);
    for (int i = 0; i < Q; i++) cin >> H[i] >> T[i];

    long sum = 0;
    int l = 1;
    int r = 2;
    for (int q = 0; q < Q; q++) {
        int target = T[q];
        int current, another;
        if (H[q] == 'L') {
            current = l;
            another = r;
            l = target;
        } else {    // R
            current = r;
            another = l;
            r = target;
        }

        if (target > current) {
            if (another < target && another > current) {    // 迂回
                sum += (N + current) - target;
            } else {    // 迂回しない
                sum += target - current;
            }
        } else {
            if (another < current && another > target) {    // 迂回
                sum += (N + target) - current;
            } else { // 迂回しない
                sum += current - target;
            }
        }
    }
    cout << sum << endl;
    return 0;
}