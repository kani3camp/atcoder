//
// Created by kani3camp on 2024/09/07.
//
#include <iostream>
using namespace std;

int main()
{
    long N;
    long Y;
    cin >> N >> Y;

    long a10000 = -1;
    long a5000 = -1;
    long a1000 = -1;

    for (long x = 0; x <= N; x++)
    {
        if (a10000 != -1) break;

        for (long y = 0; y <= N; y++)
        {
            const long z = N - x - y;
            if (z < 0) break;

            if (10000 * x + 5000 * y + 1000 * z == Y)
            {
                a10000 = x;
                a5000 = y;
                a1000 = z;
                break;
            }
        }
    }

    cout << a10000 << " " << a5000 << " " << a1000 << endl;
    return 0;
}
