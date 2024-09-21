//
// Created by kani3camp on 2024-09-21.
//


#include <iostream>
#include <cassert>
using namespace std;

int main() {
    string S;
    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] != '.') cout << S[i];
    }
    cout << endl;
    return 0;
}