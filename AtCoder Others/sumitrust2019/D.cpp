//
// Created by kani3camp on 2024-09-08.
//
#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int count = 0;

    for (int a = 0; a <= 999; a++) {
        ostringstream oss;
        oss << setw(3) << setfill('0') << a;
        string s = oss.str();

        int position = 0;
        for (int i = 0; i < S.length(); i++) {
            if (position > 2) break;
            if (s[position] == S[i]) {
                position++;
            }
        }
        if (position > 2) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}