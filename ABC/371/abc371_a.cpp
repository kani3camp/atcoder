//
// Created by kani3camp on 2024/09/14.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    char s[3];
    cin >> s[0] >> s[1] >> s[2];

    int a = 0, b=0, c=0;
    if (s[0] == '>')
    {
        a++;
    } else
    {
        b++;
    }
    if (s[1] == '>')
    {
        a++;
    } else
    {
        c++;
    }
    if (s[2] == '>')
    {
        b++;
    } else
    {
        c++;
    }
    char ans = 'A';
    if (a == 1) ans = 'A';
    if (b == 1) ans = 'B';
    if (c == 1) ans = 'C';

    cout << ans << endl;
    return 0;
}