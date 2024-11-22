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
    int N; cin >> N;
    string S; cin >> S;

    if (N % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        if (i <= (N + 1) / 2 - 1) {
            if (S[i-1] != '1') {
                cout << "No" << endl;
                return 0;
            }
        } else if (i == (N + 1) / 2) {
            if (S[i-1] != '/') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (S[i-1] != '2') {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}