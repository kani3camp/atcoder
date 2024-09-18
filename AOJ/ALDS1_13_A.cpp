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
    int k;
    cin >> k;

    int r[k], c[k];
    for (int i = 0; i < k; i++)
    {
        cin >> r[i] >> c[i];
    }

    bool filled[8][8] = {false};
    for (int i = 0; i < k; i++)
    {
        // その行はすべて
        for (int j = 0; j < 8; j++)
            filled[r[i]][j] = true;

        // その列はすべて
        for (int j = 0; j < 8; j++)
            filled[j][c[i]] = true;

        // その斜めはすべて
        for (int diff = -7; diff <= 7; diff++)
        {
            int row = r[i] + diff;
            int col = c[i] + diff;
            if (row >= 0 && col >= 0 && row <= 7 && col <= 7) { filled[row][col] = true; }
            col = c[i] - diff;
            if (row >= 0 && col >= 0 && row <= 7 && col <= 7) { filled[row][col] = true; }
        }
    }

    // 空いているマスのvector
    vector<pair<int, int> > vacants;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (filled[i][j] == false) vacants.push_back(make_pair(i, j));
        }
    }

    // 組み合わせ探索
    string flag;
    for (int i = 0; i < 8 - k; i++) flag += '1';
    for (int i = 0; i < (vacants.size() - (8 - k)); i++) flag += '0';
    sort(flag.begin(), flag.end());

    do
    {
        // filledのコピーを作成
        bool tmp_filled[8][8] = {false};
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                tmp_filled[i][j] = filled[i][j];
            }
        }
        bool ok = true;
        for (int i = 0; i < flag.size(); i++)
        {
            if (flag[i] == '0') continue;

            if (tmp_filled[vacants[i].first][vacants[i].second])
            {
                ok = false;
                break;
            }
            // tmp_filled更新
            // その行はすべて
            for (int j = 0; j < 8; j++)
                tmp_filled[vacants[i].first][j] = true;

            // その列はすべて
            for (int j = 0; j < 8; j++)
                tmp_filled[j][vacants[i].second] = true;

            // その斜めはすべて
            for (int diff = -7; diff <= 7; diff++)
            {
                int row = vacants[i].first + diff;
                int col = vacants[i].second + diff;
                if (row >= 0 && col >= 0 && row <= 7 && col <= 7) { tmp_filled[row][col] = true; }
                col = vacants[i].second - diff;
                if (row >= 0 && col >= 0 && row <= 7 && col <= 7) { tmp_filled[row][col] = true; }
            }
        }
        if (ok)
        {
            bool set[8][8] = {false};
            for (int i = 0; i < k; i++)
            {
                set[r[i]][c[i]] = true;
            }
            for (int i = 0; i < flag.size(); i++)
            {
                if (flag[i] == '0') continue;
                set[vacants[i].first][vacants[i].second] = true;
            }
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (set[i][j])
                        cout << 'Q';
                    else
                        cout << '.';
                    if (j == 7) cout << endl;
                }
            }
        }
    }
    while (next_permutation(flag.begin(), flag.end()));

    return 0;
}
