//
// Created by kani3camp on 2024-10-05.
//


#include <iostream>
#include <cassert>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    if (S == T) {
        cout << 0 << endl;
        return 0;
    }

    const int n = min(S.length(), T.length());
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << n + 1 << endl;
    return 0;
}