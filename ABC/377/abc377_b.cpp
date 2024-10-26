//
// Created by kani3camp on 2024-10-26.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n = 8;
    set<int> r, c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '#') {
                r.insert(i);
                c.insert(j);
            }
        }
    }

    cout << (8 - r.size()) * (8 - c.size()) << endl;

    return 0;
}