//
// Created by kani3camp on 2024/11/09.
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

int main()
{
    int N; cin >> N;

    string s = std::to_string(N);
    char a = s[0];
    char b = s[1];
    char c = s[2];

    cout << b << c << a << " ";
    cout << c << a << b << endl;

    return 0;
}