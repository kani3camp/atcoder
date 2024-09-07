//
// Created by kani3camp on 2024-09-07.
//

#include <iostream>
using namespace std;

int main() {
  int L, R;
  cin >> L >> R;

  if (L == 1 && R == 0) {
    cout << "Yes" << endl;
  } else if (L == 0 && R == 1) {
    cout << "No" << endl;
  } else {
    cout << "Invalid" << endl;
  }

  return 0;
}