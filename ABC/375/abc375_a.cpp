//
// Created by kani3camp on 2024-10-12.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int count = 0;
    for (int i = 0; i < N-2; i++) {
        if (S[i]== '#' && S[i+2] == '#' && S[i+1] == '.') {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
