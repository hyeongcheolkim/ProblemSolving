#include <bits/stdc++.h>
using namespace std;

constexpr char OUT_OF_BOUND = 0;
constexpr int dr[]{0, 0, 0, +1, -1, +1, +1, -1, -1}, dc[]{0, +1, -1, 0, 0, +1, -1, +1, -1};
array<array<char, 8 + 2>, 8 + 2> maze;
deque<pair<int, int>> walls;
queue<pair<int, int>> q, tmp;

void move_wall()
{
    int size = walls.size();
    while (size--)
    {
        auto [r, c] = walls.front();
        walls.pop_front();
        maze[r][c] = '.';
        if (maze[r + 1][c] == OUT_OF_BOUND)
            continue;
        walls.emplace_back(r + 1, c);
    }
    for (const auto& [r, c] : walls)
        maze[r][c] = '#';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '#')
                walls.emplace_back(i, j);
        }
    q.emplace(8, 1);
    while (!q.empty())
    {
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            if (maze[r][c] == '#')
                continue;
            for (int direction = 0; direction < 9; ++direction)
            {
                int nr = r + dr[direction];
                int nc = c + dc[direction];
                if (maze[nr][nc] == OUT_OF_BOUND || maze[nr][nc] == '#')
                    continue;
                if (nr == 1 && nc == 8)
                {
                    cout << 1;
                    exit(0);
                }
                tmp.emplace(nr, nc);
            }
        }
        q.swap(tmp);
        move_wall();
    }
    cout << 0;
    return 0;
}