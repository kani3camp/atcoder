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
    cin >> N;
    vector<vector<char> > A(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<char> > newA(N, vector<char>(N, '-'));
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            int d = min(min(x, y), min(N + 1 - x, N + 1 - y));
            d = d % 4;

            if (d == 1) {
                int newx = y;
                int newy = N + 1 - x;
                newA[newx - 1][newy - 1] = A[x - 1][y - 1];
            } else if (d == 2) {
                int newx = N + 1 - x;
                int newy = N + 1 - y;
                newA[newx - 1][newy - 1] = A[x - 1][y - 1];
            } else if (d == 3) {
                int newx = N + 1 - y;
                int newy = x;
                newA[newx - 1][newy - 1] = A[x - 1][y - 1];
            } else {
                newA[x - 1][y - 1] = A[x - 1][y - 1];
            }
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout << newA[x][y];
        }
        cout << endl;
    }
    return 0;
}
