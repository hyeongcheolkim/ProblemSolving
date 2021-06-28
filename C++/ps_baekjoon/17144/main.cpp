//baekjoon ps 17144

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int dr[] = {0, 0, +1, -1};
    constexpr int dc[] = {+1, -1, 0, 0};
    int r, c, t;
    int r1 = -5, r2 = -5;
    int sum = 0;
    cin >> r >> c >> t;
    vector<vector<int>> map(r + 2, vector<int>(c + 2, -5));
    vector<vector<int>> temp(r + 2, vector<int>(c + 2, 0));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == -1)
            {
                r1 = r2;
                r2 = i;
            }
        }
    auto spread = [&]
    {
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                temp[i][j] = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                if (map[i][j] > 0)
                {
                    int num = 0;
                    int dust = map[i][j] / 5;
                    for (int d = 0; d < sizeof(dr) / sizeof(int); d++)
                        if (map[i + dr[d]][j + dc[d]] >= 0)
                        {
                            num++;
                            temp[i + dr[d]][j + dc[d]] += dust;
                        }
                    map[i][j] -= dust * num;
                }
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                map[i][j] += temp[i][j];
    };
    auto wind = [&]()
    {
        for (int row = r1 - 1; row > 1; row--)
            map[row][1] = map[row - 1][1];
        for (int col = 1; col < c; col++)
            map[1][col] = map[1][col + 1];
        for (int row = 1; row < r1; row++)
            map[row][c] = map[row + 1][c];
        for (int col = c; col > 1; col--)
            map[r1][col] = map[r1][col - 1];
        map[r1][2] = 0;
        for (int row = r2 + 1; row < r; row++)
            map[row][1] = map[row + 1][1];
        for (int col = 1; col < c; col++)
            map[r][col] = map[r][col + 1];
        for (int row = r; row > r2; row--)
            map[row][c] = map[row - 1][c];
        for (int col = c; col > 1; col--)
            map[r2][col] = map[r2][col - 1];
        map[r2][2] = 0;
    };
    while (t--)
    {
        spread();
        wind();
    }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (map[i][j] > 0)
                sum += map[i][j];
    cout << sum;
    return 0;
}