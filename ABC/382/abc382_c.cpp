//
// Created by kani3camp on 2024/11/30.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
#include <numeric>

using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    set<pair<int, int> > A;

    int current_min = INT_MAX;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (current_min > a) {
            A.insert({a, i+1});
            current_min = a;
        }
    }

    for (int i = 0; i < M; i++) {
        int B; cin >> B;
        auto it = A.upper_bound({B, INT_MAX});
        if (it != A.begin()) {
            --it;
            cout << it->second << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}