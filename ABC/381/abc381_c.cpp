//
// Created by kani3camp on 2024/11/22.
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
    int N;
    cin >> N;
    string S;
    cin >> S;

    long count1 = 0;
    long count2 = 0;
    long count_slash = 0;
    long max = 0;
    for (const char c : S) {
        switch (c) {
        case '1':
            if (count_slash > 0) {
                count1 = 0;
                count2 = 0;
                count_slash = 0;
            }
            count1++;
            if (count2 > 0) {
                count2 = 0;
                count_slash = 0;
                continue;
            }
            break;
        case '2':
            if (count_slash == 0 && count1 > 0) {
                count1 = 0;
                count2 = 0;
                count_slash = 0;
                continue;
            }
            count2++;
            if (count_slash == 0) {
                count1 = 0; count2 = 0; count_slash = 0;
                continue;
            }
            if (count2 <= count1) {
                if (count2 > max) max = count2;
                continue;
            }
            break;
        case '/':
            count_slash++;
            if (count_slash > 1 || count2 > 0) {
                count1 = 0; count2 = 0; count_slash = 0;
                continue;
            }
            if (count1 > 0 && count_slash == 1) {
                continue;
            }
            count1 = 0;
            count2 = 0;
            count_slash = 0;
            break;
        }
    }

    cout << 2 * max + 1 << endl;

    return 0;
}