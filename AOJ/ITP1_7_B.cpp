//
// Created by kani3camp on 2024-09-08.
//
#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n, x;
        cin >> n >> x;

        if (n == 0 && x == 0) {
            break;
        }

        long long count = 0;
        for (int n1 = 1; n1 <= n - 2; n1++) {
            for (int n2 = n1 + 1; n2 <= n - 1; n2++) {
                for (int n3 = n2 + 1; n3 <= n; n3++) {
                    if (n1 + n2 + n3 == x) {
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}