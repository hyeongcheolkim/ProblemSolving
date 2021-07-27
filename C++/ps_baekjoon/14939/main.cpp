//baekjoon ps 14939

#include <iostream>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int SIZE = 10;
constexpr int INF = numeric_limits<int>::max();
array<array<char, SIZE + 2>, SIZE + 2> input;
int res = INF;

void on_off_bulb(const int &row, const int &col, array<array<char, SIZE + 2>, SIZE + 2> &map)
{
    constexpr int dr[] = {0, 0, 0, +1, -1};
    constexpr int dc[] = {0, +1, -1, 0, 0};
    for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
    {
        char &nowpos = map[row + dr[i]][col + dc[i]];
        if (nowpos == '#')
            nowpos = 'O';
        else
            nowpos = '#';
    }
}

int fnc(const array<bool, SIZE + 1> &check)
{
    int cnt = 0;
    auto map = input;
    for (int col = 1; col <= SIZE; col++)
        if (check[col])
        {
            on_off_bulb(1, col, map);
            cnt++;
        }
    for (int row = 2; row <= SIZE; row++)
        for (int col = 1; col <= SIZE; col++)
            if (map[row - 1][col] == 'O')
            {
                on_off_bulb(row, col, map);
                cnt++;
            }
    for (int col = 1; col <= SIZE; col++)
        if (map[SIZE][col] != '#')
            cnt = INF;
    return cnt;
}

void dfs(int cursor, array<bool, SIZE + 1> check)
{
    static constexpr int end_condition = 11;

    if (cursor == end_condition)
    {
        auto cnt = fnc(check);
        res = min(res, cnt);
        return;
    }
    dfs(cursor + 1, check);
    check[cursor] = true;
    dfs(cursor + 1, check);
}

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            cin >> input[i][j];
    array<bool, SIZE + 1> check;
    check.fill(false);
    dfs(1, check);
    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}