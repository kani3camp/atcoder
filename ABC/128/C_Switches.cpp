//
// Created by kani3camp on 2024/09/08.
//
#include <iostream>
#include <vector>

using namespace std;

// x ** y
int pow(int x, int y)
{
    int result = x;
    for (int i = 1; i < y; i++) // xにy-1回xをかける
    {
        result = result * x;
    }
    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> k(M);
    vector<vector<int> > s(M);
    vector<int> p(M);

    for (int i = 0; i < M; i++)
    {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            int s_input;
            cin >> s_input;
            s[i].push_back(s_input);
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> p[i];
    }

    // マスクビット作成
    vector<int> mask(M);
    for (int i = 0; i < M; i++)
    {
        mask[i] = 0;
        for (int j = 0; j < k[i]; j++)
        {
            mask[i] |=  1 << (s[i][j] -1);
        }
        // cout << "mask[i] = " << bitset<8>(mask[i]) << endl;
    }

    // ビット全探索
    long count = 0;
    for (int n = 0; n < pow(2, N); n++)
    {
        long m_count = 0;
        for (int m = 0; m < M; m++) // その電球がつくか
        {
            if (__builtin_popcount(n & mask[m]) % 2 != p[m])  // 満たさない時点で次の電球のつき方へ
            {
                break;
            }
            m_count++;
        }
        if (m_count == M) count++;
    }

    cout << count << endl;
    return 0;
}