//
// Created by kani3camp on 2024-10-26.
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
    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > range(N);
    for (int i = 0; i < N; i++) {
        cin >> range[i].first >> range[i].second;
    }
    // rangeをソート
    sort(range.begin(), range.end(),
         [](const pair<int, int> a, const pair<int, int> b) {
             return a.second < b.second;
         }
    );

    long sum = 0;
    for (int i = 0; i <= N; i++) {
        int l, r;
        if (i == 0) {
            l = 1;
            r = range[i].second;
        } else if (i == N) {
            l = range[i - 1].first;
            r = M;
        } else {
            l = range[i - 1].first;
            r = range[i].second;
        }

        for (int j = l; j < r; j++) {
            sum += (r - j) * (r - j);
        }
    }

    return 0;
}
