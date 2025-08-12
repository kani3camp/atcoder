//
// Created by 白坂潤 on 2025/08/12.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    string A_str, B_str, C_str;
    cin >> A_str >> B_str >> C_str;

    vector<int> A = {A_str[0] - '0', A_str[1] - '0', A_str[2] - '0', A_str[3] - '0'};
    vector<int> B = {B_str[0] - '0', B_str[1] - '0', B_str[2] - '0', B_str[3] - '0'};
    vector<int> C = {C_str[0] - '0', C_str[1] - '0', C_str[2] - '0', C_str[3] - '0'};

    set<int> a_set;
    set<int> b_set;
    set<int> c_set;

    a_set.insert(A[0] + A[1] + A[2] + A[3]);
    a_set.insert(A[0] + A[1] + A[2] - A[3]);
    a_set.insert(A[0] + A[1] - A[2] + A[3]);
    a_set.insert(A[0] + A[1] - A[2] - A[3]);
    a_set.insert(A[0] - A[1] + A[2] + A[3]);
    a_set.insert(A[0] - A[1] + A[2] - A[3]);
    a_set.insert(A[0] - A[1] - A[2] + A[3]);
    a_set.insert(A[0] - A[1] - A[2] - A[3]);

    b_set.insert(B[0] + B[1] + B[2] + B[3]);
    b_set.insert(B[0] + B[1] + B[2] - B[3]);
    b_set.insert(B[0] + B[1] - B[2] + B[3]);
    b_set.insert(B[0] + B[1] - B[2] - B[3]);
    b_set.insert(B[0] - B[1] + B[2] + B[3]);
    b_set.insert(B[0] - B[1] + B[2] - B[3]);
    b_set.insert(B[0] - B[1] - B[2] + B[3]);
    b_set.insert(B[0] - B[1] - B[2] - B[3]);

    c_set.insert(C[0] + C[1] + C[2] + C[3]);
    c_set.insert(C[0] + C[1] + C[2] - C[3]);
    c_set.insert(C[0] + C[1] - C[2] + C[3]);
    c_set.insert(C[0] + C[1] - C[2] - C[3]);
    c_set.insert(C[0] - C[1] + C[2] + C[3]);
    c_set.insert(C[0] - C[1] + C[2] - C[3]);
    c_set.insert(C[0] - C[1] - C[2] + C[3]);
    c_set.insert(C[0] - C[1] - C[2] - C[3]);

    vector<int> answers;
    for (const int i : a_set) {
        for (const int j : b_set) {
            for (const int k : c_set) {
                if (i == j && j == k) {
                    answers.push_back(i);
                }
            }
        }
    }

    if (answers.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        bool first = true;
        for (const int &a : answers) {
            if (!first) {
                cout << ' ';
            } else {
                first = false;
            }
            cout << a;
        }
        cout << endl;
    }

    return 0;
}