//
// Created by kani3camp on 2024/10/20.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vector<vector<char> > c(R, vector<char>(C));
    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            cin >> c[row][col];
        }
    }

    vector<vector<int> > dist(R, vector<int>(C, -1));
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    dist[sy][sx] = 0;
    while (!q.empty())
    {
        int current_y = q.front().first, current_x = q.front().second;

        // 上下
        for (int y = current_y - 1; y <= current_y + 1; y += 2)
        {
            int x = current_x;
            if (x >= 0 && x < C && y >= 0 && y < R)
            {
                if (c[y][x] == '#') continue;
                if (y == gy && x == gx)
                {
                    cout << dist[current_y][current_x] + 1 << endl;
                    return 0;
                }
                if (dist[y][x] == -1)
                {
                    dist[y][x] = dist[current_y][current_x] + 1;
                    q.push(make_pair(y, x));
                }
            }
        }
        // 左右
        for (int x = current_x - 1; x <= current_x + 1; x += 2)
        {
            int y = current_y;
            if (x >= 0 && x < C && y >= 0 && y < R)
            {
                if (c[y][x] == '#') continue;
                if (y == gy && x == gx)
                {
                    cout << dist[current_y][current_x] + 1 << endl;
                    return 0;
                }
                if (dist[y][x] == -1)
                {
                    dist[y][x] = dist[current_y][current_x] + 1;
                    q.push(make_pair(y, x));
                }
            }
        }
        q.pop();
    }

    return 0;
}
