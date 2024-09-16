//
// Created by kani3camp on 2024/09/14.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int A[M];
    char B[M];
    for (int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i];
    }

    vector<int> M_count(N, 0);
    for (int i = 0; i < M; i++)
    {
        if (B[i] == 'M')
        {
            if (M_count[A[i] - 1] == 0)
            {
                cout << "Yes" << endl;
            } else
            {
                cout << "No" << endl;
            }
            M_count[A[i] - 1]++;
        } else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}