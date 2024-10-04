//
// Created by kani3camp on 2024/09/28.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long N, M;
long P[200000009];

int main()
{
    cin >> N >> M;
    P[0] = 0;   // １〜４回それぞれ求めなくていいように、0点があるとする。これで4回投げることに集中できる。
    for (long i = 1; i < N+1; i++)
    {
        cin >> P[i];
    }

    long S[(N+1)*(N+1)];
    for (long i = 0; i < N+1; i++)
    {
        for (long j = 0; j < N+1; j++)
        {
            S[i+j*(N+1)] = P[i] + P[j];
        }
    }

    sort(S, S+(N+1)*(N+1)); // N^2 log(N^2)

    long max = 0;
    for (long i = 0; i < (N+1)*(N+1); i++)
    {
        // 二分探索
        long L = 0;
        long R = (N+1)*(N+1)-1;
        while (L <= R)
        {
            long Mid = (L+R)/2;
            if (S[i] + S[Mid] > M)
            {
                R = Mid - 1;
            }
            if (S[i] + S[Mid] == M)
            {
                cout << M << endl;
                return 0;
            }
            if (S[i] + S[Mid] < M)
            {
                if (S[i] + S[Mid] > max) max = S[i] + S[Mid];
                if (L == Mid) break;
                L = Mid;
            }
        }
    }

    cout << max << endl;

    return 0;
}