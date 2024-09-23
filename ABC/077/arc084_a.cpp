//
// Created by kani3camp on 2024/09/23.
//


#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    multiset<int> A, B, C;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        A.insert(input);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        B.insert(input);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        C.insert(input);
    }

    long sum = 0;
    auto max_it_b = B.begin();
    auto max_it_c = C.begin();
    for (auto it_a = A.begin(); it_a != A.end(); ++it_a)
    {
        max_it_b = upper_bound(max_it_b, B.end(), *it_a);
        max_it_c = upper_bound(max_it_c, C.end(), *max_it_b);
        for (auto it_b = max_it_b; it_b != B.end(); ++it_b)
        {
            sum += distance(upper_bound(max_it_c, C.end(), *it_b), C.end());
        }
    }

    cout << sum << endl;

    return 0;
}