//
// Created by kani3camp on 2024/09/18.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    cin >> n;
    int S[n];
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    cin >> q;
    int T[q];
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }

    int C = 0;
    for (int i = 0; i < q; i++) {
        int target = T[i];

        int L = 0;
        int R = n - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (target < S[M]) R = M - 1;
            if (target == S[M]) {
                C++; break;
            }
            if (target > S[M]) L = M + 1;
        }
    }

    cout << C << endl;

    return 0;
}