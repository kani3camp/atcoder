//
// Created by kani3camp on 2024-09-13.
//


#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int n, m;
    cin >> m;

    long target_x[m], target_y[m];
    for (int i = 0; i < m; i++) {
        cin >> target_x[i] >> target_y[i];
    }

    cin >> n;
    long x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        // m=0の点を当てはめる。移動差分
        long move_x = x[i] - target_x[0];
        long move_y = y[i] - target_y[0];

        int ok = 0; // はまった星の数
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (x[j] == target_x[k] + move_x && y[j] == target_y[k] + move_y) {
                    ok++;
                    break;
                }
            }
        }
        if (ok == m) {
            cout << move_x << " " << move_y << endl;
            return 0;
        }
    }

    return 0;
}