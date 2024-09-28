//
// Created by kani3camp on 2024/09/28.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<long long> A;
    vector<long long> B;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        A.emplace_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        long long b;
        cin >> b;
        B.emplace_back(b);
    }

    cout << *max_element(A.begin(), A.end()) + *max_element(B.begin(), B.end()) << endl;

    return 0;
}