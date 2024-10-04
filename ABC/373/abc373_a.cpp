//
// Created by kani3camp on 2024/09/28.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str[12];
    for (int i = 0; i < 12; i++)
    {
        cin >> str[i];
    }

    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        if (str[i].size() == i + 1) sum++;
    }

    cout << sum << endl;

    return 0;
}