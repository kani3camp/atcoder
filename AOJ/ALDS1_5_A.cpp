//
// Created by kani3camp on 2024-09-09.
//
#include <iostream>
#include <vector>
using namespace std;

long long pow(const long long x, const long long y) {
    long long result = 1;
    for (long long i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

int main() {
    int n, q;

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    vector<int> m(q);
    for (int i = 0; i < q; i++) {
        cin >> m[i];
    }

    vector<bool> answer(q, false);

    for (int i = 0; i < pow(2, n); i++) {
        long sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += a[j];
        }
        for (int j = 0; j < q; j++) {
            if (sum == m[j]) answer[j] = true;
        }
    }

    for (int i = 0; i < q; i++) {
        if (answer[i]) cout << "yes" << endl;
        else cout << "no" << endl;
    }


    return 0;
}