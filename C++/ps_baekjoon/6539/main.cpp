//baekjoon ps 6539

#include <bits/stdc++.h>

using namespace std;
using pos = tuple<int, int, int>;

int main()
{
    constexpr char OUT_OF_BOUND = 0;
    constexpr int dl[] = {0, 0, 0, 0, +1, -1};
    constexpr int dr[] = {0, 0, +1, -1, 0, 0};
    constexpr int dc[] = {+1, -1, 0, 0, 0, 0};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r, c;
    while (cin >> l >> r >> c, !(l == 0 && r == 0 && c == 0))
    {
        vector<vector<vector<char>>> map(l + 2, vector<vector<char>>(r + 2, vector<char>(c + 2, OUT_OF_BOUND)));
        vector<vector<vector<bool>>> visit(l + 2, vector<vector<bool>>(r + 2, vector<bool>(c + 2, false)));
        pos s, e;
        bool flag = false;
        for (int layer = 1; layer <= l; ++layer)
            for (int row = 1; row <= r; ++row)
                for (int col = 1; col <= c; ++col)
                {
                    cin >> map[layer][row][col];
                    if (map[layer][row][col] == 'S')
                        s = {layer, row, col};
                    if (map[layer][row][col] == 'E')
                        e = {layer, row, col};
                }
        queue<pair<pos, int>> q;
        q.emplace(s, 0);
        auto [s_layer, s_row, s_col] = s;
        visit[s_layer][s_row][s_col] = true;
        while (!q.empty())
        {
            auto [now_layer, now_row, now_col] = q.front().first;
            int cnt = q.front().second;
            if (q.front().first == e)
            {
                flag = true;
                break;
            }
            q.pop();
            for (int direction = 0; direction < sizeof(dl) / sizeof(int); ++direction)
            {
                int next_layer = now_layer + dl[direction];
                int next_row = now_row + dr[direction];
                int next_col = now_col + dc[direction];
                if (map[next_layer][next_row][next_col] == OUT_OF_BOUND || visit[next_layer][next_row][next_col])
                    continue;
                if (map[next_layer][next_row][next_col] != '#')
                {
                    q.emplace(pos{next_layer, next_row, next_col}, cnt + 1);
                    visit[next_layer][next_row][next_col] = true;
                }
            }
        }
        if (flag)
            cout << "Escaped in " << q.front().second << " minute(s)." << '\n';
        else
            cout << "Trapped!" << '\n';
    }
    return 0;
}