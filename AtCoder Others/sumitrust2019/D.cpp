//
// Created by kani3camp on 2024-09-08.
//
#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    set<string> candidates;
    for (int i = 0; i < S.length() - 2; i++) {
        for (int j = i + 1; j < S.length() - 1; j++) {
            for (int k = j + 1; k < S.length(); k++) {
                string s = string(1, S[i] )+ S[j] + S[k];
                candidates.insert(s);
            }
        }
    }
    cout << candidates.size() << endl;
    return 0;
}