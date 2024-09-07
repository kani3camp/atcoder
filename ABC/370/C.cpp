//
// Created by kani3camp 2024-09-07.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string min_string(vector<string> candidates) {
    const int STR_LEN = candidates[0].length();
    vector<char> min_chars;

    for (int i = 0; i < STR_LEN; i++) {
        char min_char = candidates[0][i];

        for (int j = 0; j < candidates.size(); j++) {
            if (candidates[j].at(i) < min_char) {
                min_char = candidates[j].at(i);
            }
        }
        min_chars.push_back(min_char);

        // 当てはまらない候補は削除
        candidates.erase(
            std::remove_if(candidates.begin(), candidates.end(), [i, min_char](string s) { return s.at(i) != min_char; }),
            candidates.end()
            );
    }
    std::string str(min_chars.begin(), min_chars.end());
    return str;
}

int main() {
    string S, T;
    cin >> S;
    cin >> T;

    const auto STR_LEN = S.length();
    vector<string> X;

    while (S != T) {
        vector<string> candidates;
        for (int i = 0; i < STR_LEN; i++) {
            if (S[i] != T[i]) {
                string candidate = S;
                candidate[i] = T[i];
                candidates.push_back(candidate);
            }
        }
        if (!candidates.empty()) {
            S = min_string(candidates);
            X.push_back(S);
        }
        // cout << "hello S: " << S << endl;
    }
    // cout << "終わった" << endl;

    cout << X.size() << endl;
    for (int i = 0; i < X.size(); i++) {
        cout << X[i] << endl;
    }

    return 0;
}

