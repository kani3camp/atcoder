//
// Created by kani3camp on 2024-09-08.
//
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    long arr[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    long long max_sum = 0;
    for (int t1 = 0; t1 < M-1; t1++) {
        for (int t2 = t1+1; t2 < M; t2++) {
            // 各生徒が歌唱
            long long sum = 0;
            for (int k = 0; k < N; k++) {
                sum += max(arr[k][t1], arr[k][t2]);
            }
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}