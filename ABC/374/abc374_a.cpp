//
// Created by kani3camp on 2024-10-05.
//


#include <iostream>
#include <cassert>
using namespace std;

int main() {
    string S;
    cin >> S;

    if (S.substr(S.size() - 3) == "san") cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}