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
    int N, D; cin >> N >> D;
    string S; cin >> S;

    int count = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '@') {
            count++;
        }
    }
    int first_vacant = N - count;
    cout << first_vacant + D << endl;

    return 0;
}