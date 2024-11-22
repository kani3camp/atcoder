//
// Created by kani3camp on 2024/11/22.
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
    string S; cin >> S;

    // 偶数か
    if (S.size() % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    set<char> c;

    // 2文字ずつ連続か
    for (int i = 1; i <= S.size() / 2; i++) {
        if (S[2 * i - 1] != S[2 * i - 1 - 1]) {
            cout << "No" << endl;
            return 0;
        }
        c.insert(S[2 * i - 1]);
    }

    // 各文字2回ずつの登場か
    if (S.size() / 2 == c.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}