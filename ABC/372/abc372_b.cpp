//
// Created by kani3camp on 2024-09-21.
//


#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int pow(int base, int exp) {
    int result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int M;
    cin >> M;

    vector<int> A;
    int current_a = 10;
    while (M > 0) {
        if (M >= pow(3, current_a)) {
            A.push_back(current_a);
            M = M - pow(3, current_a);
        } else {
            current_a--;
        }
    }
    cout << A.size() << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}