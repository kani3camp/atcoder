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
  vector<pair<int, long long> > XA(M);

  for (long long i = 0; i < M; i++) {
    cin >> XA[i].first;
  }
  for (long long i = 0; i < M; i++) {
    cin >> XA[i].second;
  }

  // NOTE: これが必要だった
  sort(XA.begin(), XA.end());

  long long num = 0;
  if (XA[0].first > 1) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = 0; i < M; i++) {
    long long next_X;
    if (i == M - 1) {
      next_X = N + 1;
    } else {
      next_X = XA[i + 1].first;
    }

    if (XA[i].second == 1) {
      if (next_X - XA[i].first > 1) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      long distance = next_X - XA[i].first;
      if (distance > XA[i].second) {
        cout << -1 << endl;
        return 0;
      }

      num += distance * (distance - 1) / 2;

      if (distance < XA[i].second) {  // のこったのは次に繰り越し
        if (i == M - 1) {
          cout << -1 << endl;
          return 0;
        }
        XA[i + 1].second += XA[i].second - 1 - (distance - 1);
        num += distance * ((XA[i].second - 1) - (distance - 1));
      }
    }
  }

  cout << num << endl;

  return 0;
}