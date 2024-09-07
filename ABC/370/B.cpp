//
// Created by kani3camp on 2024-09-07.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    int current_num = 1;
    for (int i = 1; i <= N; i++) {
        if (current_num >= i) {
            current_num = arr[current_num-1][i-1];
        } else {
            current_num = arr[i-1][current_num-1];
        }
    }

    cout << current_num << endl;
}