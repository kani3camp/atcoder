//
// Created by kani3camp on 2024/09/08.
//
#include <iostream>
using namespace std;


int main()
{
    int N;
    cin >> N;

    int count = 0;
    for (int i = 1; i <= N; i+=2)
    {
        int ok = 0;
        for (int j = 1; j <= N; j+=2)
        {
            if (i % j == 0) ok++;
        }
        if (ok == 8) count++;
    }

    cout << count << endl;
    return 0;
}
