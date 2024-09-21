//
// Created by kani3camp on 2024-09-21.
//


#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int N;
    cin >> N;

    int H[N];
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int c[N] = {}; // answer

    for (int j = N - 1; j > 0; j--) {
        int i = j - 1;
        while (i >= 0) {
            if (H[i] < H[j]) {
                c[i]++;
                i--;
            } else {
                c[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
