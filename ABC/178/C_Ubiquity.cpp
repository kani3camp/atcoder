//
// Created by kani3camp on 2024/09/07.
//
using namespace std;
#include <iostream>

const long long P = 1000000007;

int main()
{
    long long N;
    cin >> N;

    long long a1 = 1;
    long long a2 = 1;
    long long a3 = 1;

    for (long long i = 1; i <= N; i++)
    {
        a1 = (a1 * 10) % P;
    }

    for (long long i = 1; i <= N; i++)
    {
        a2 = (a2 * 9) % P;
    }

    for (long long i = 1; i <= N; i++)
    {
        a3 = (a3 * 8) % P;
    }

    long long answer = (a1 - a2 - a2 + a3) % P;

    answer = (answer + P) % P;  // answerが負の場合があるので正になおす

    cout << answer << endl;
    return 0;
}
