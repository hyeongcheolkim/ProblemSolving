//baekjoon ps 17070

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

enum State
{
    EAST,
    NORTH,
    NORTHEAST
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int cnt = 0;
    cin >> n;
    vector<vector<int>> map(n + 2, vector<int>(n + 2, -1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    function<void(int, int)> dfs = [&](int row, int col)
    {
        static State state = State::EAST;
        if (row == n && col == n)
        {
            cnt++;
            return;
        }
        switch (state)
        {
            int nextrow;
            int nextcol;
        case State::EAST:
            nextcol = col + 1;
            nextrow = row;
            if (map[nextrow][nextcol] == 0)
            {
                state = State::EAST;
                dfs(nextrow, nextcol);
                state = State::EAST;
            }
            nextcol = col + 1;
            nextrow = row + 1;
            if (map[nextrow][nextcol] == 0 && map[nextrow - 1][nextcol] == 0 && map[nextrow][nextcol - 1] == 0)
            {
                state = State::NORTHEAST;
                dfs(nextrow, nextcol);
                state = State::EAST;
            }
            break;
        case State::NORTH:
            nextcol = col;
            nextrow = row + 1;
            if (map[nextrow][nextcol] == 0)
            {
                state = State::NORTH;
                dfs(nextrow, nextcol);
                state = State::NORTH;
            }
            nextcol = col + 1;
            nextrow = row + 1;
            if (map[nextrow][nextcol] == 0 && map[nextrow - 1][nextcol] == 0 && map[nextrow][nextcol - 1] == 0)
            {
                state = State::NORTHEAST;
                dfs(nextrow, nextcol);
                state = State::NORTH;
            }
            break;
        case State::NORTHEAST:
            nextcol = col + 1;
            nextrow = row;
            if (map[nextrow][nextcol] == 0)
            {
                state = State::EAST;
                dfs(nextrow, nextcol);
                state = State::NORTHEAST;
            }
            nextcol = col;
            nextrow = row + 1;
            if (map[nextrow][nextcol] == 0)
            {
                state = State::NORTH;
                dfs(nextrow, nextcol);
                state = State::NORTHEAST;
            }
            nextcol = col + 1;
            nextrow = row + 1;
            if (map[nextrow][nextcol] == 0 && map[nextrow - 1][nextcol] == 0 && map[nextrow][nextcol - 1] == 0)
            {
                state = State::NORTHEAST;
                dfs(nextrow, nextcol);
                state = State::NORTHEAST;
            }
            break;
        }
    };
    dfs(1, 2);
    cout << cnt;
    return 0;
}