//
// Created by kani3camp on 2024/09/28.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    char c[26];
    for (int i = 0; i < 26; i++)
    {
        cin >> c[i];
    }

    int sum = 0;
    for (char current_char = 'A'; current_char < 'Z'; current_char++)
    {
        // search
        int current_i;
        for (int i = 0; i < 26; i++)
        {
            if (c[i] == current_char)
            {
                current_i = i;
                break;
            }
        }
        char next = current_char + 1;

        for (int i = 0; i < 26; i++)
        {
            if (c[i] == next)
            {
                sum += abs(i - current_i);
            }
        }
    }

    cout << sum << endl;

    return 0;
}