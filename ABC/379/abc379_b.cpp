//
// Created by kani3camp on 2024/11/09.
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
    int N, K; cin >> N >> K;
    string S; cin >> S;

    int sum = 0;
    int counter = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'O') {
            counter++;
        } else {
            counter = 0;
        }
        if (counter == K) {
            sum++;
            counter = 0;
        }
    }

    cout << sum << endl;

    return 0;
}