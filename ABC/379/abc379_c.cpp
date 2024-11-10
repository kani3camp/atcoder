//
// Created by kani3camp on 2024/11/09.
//

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  vector<long long> X(M), A(M);

  for (long long i = 0; i < M; i++) {
    cin >> X[i];
  }
  for (long long i = 0; i < M; i++) {
    cin >> A[i];
  }

  long long num = 0;
  if (X[0] > 1) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = 0; i < M; i++) {
    long long next_X;
    if (i == M - 1) {
      next_X = N + 1;
    } else {
      next_X = X[i + 1];
    }

    if (A[i] == 1) {
      if (next_X - X[i] > 1) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      long distance = next_X - X[i];
      if (distance > A[i]) {
        cout << -1 << endl;
        return 0;
      }

      num += distance * (distance - 1) / 2;

      if (distance < A[i]) {  // のこったのは次に繰り越し
        if (i == M - 1) {
          cout << -1 << endl;
          return 0;
        }
        A[i + 1] += A[i] - 1 - (distance - 1);
        num += distance * ((A[i] - 1) - (distance - 1));
      }
    }
  }

  cout << num << endl;

  return 0;
}