//
// Created by kani3camp on 2024/11/22.
//

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    long max = 0;
    int prev = -1;
    auto first_it = A.begin();

    for (auto it = A.begin(); it != A.end(); ++it) {
        if (prev == -1) { // 連続1個目
            prev = *it;
            continue;
        }
        if (*it == prev) {
            // 連続2個目
            if (max == 0) max = 1;
            prev = -1;

            auto found = find(first_it, it - 1, *it);
            if (found != it-1) { // found
                first_it = it;
                continue;
            }
            // 長さ更新
            auto length = distance(first_it, it) / 2 + 1;
            if (max < length)
                max = length;
        } else { // 1個目と2個目が違う
            first_it = it;
            prev = *it;
            continue;
        }
    }

    cout << max * 2 << endl;

    return 0;
}