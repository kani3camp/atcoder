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
#include <cassert>

using namespace std;

int main()
{
    int N, D; cin >> N >> D;
    string S; cin >> S;

    int count = 0;
    assert(N == S.size());
    for (int i = N-1; i >= 0; i--) {
        if (S[i] == '@') {
            count++;
            if (count <= D) {
                S[i] = '.';
            }
        }
    }

    cout << S << endl;

    return 0;
}