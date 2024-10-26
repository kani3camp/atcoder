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
    string s;
    cin >> s;

    vector<char> remain = {'A', 'B', 'C'};
    for (auto c : s) {
        for (auto j = remain.begin(); j != remain.end(); ++j) {
            if (c == *j) {
                remain.erase(j);
                break;
            }
        }
    }
    if (remain.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}