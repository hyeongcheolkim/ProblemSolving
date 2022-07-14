#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};

bool is_visited(int my_key, int target_key)
{
    for (char c = 'a'; c <= 'z' + 1; ++c)
    {
        int cmp_bit = (1 << (c - 'a'));
        if (my_key & cmp_bit)
            if (!(target_key & cmp_bit))
                return false;
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int h, w, start_key = 0, res = 0;
        cin >> h >> w;
        vector<vector<char>> board(h + 2, vector<char>(w + 2, '.'));
        vector<vector<int>> vst(h + 2, vector<int>(w + 2));
        queue<tuple<int, int, int>> q;
        string start_key_string;
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                cin >> board[i][j];
        cin >> start_key_string;
        if (start_key_string != "0")
            for (const auto& e : start_key_string)
                start_key |= (1 << (e - 'a'));
        start_key |= (1 << ('z' - 'a' + 1));
        vst[0][0] = start_key;
        q.emplace(0, 0, start_key);
        while (!q.empty())
        {
            auto [r, c, key] = q.front();
            q.pop();
            for (int direction = 0; direction < 4; ++direction)
            {
                int nr = r + dr[direction];
                int nc = c + dc[direction];
                if (!(0 <= nr && nr <= h + 1 && 0 <= nc && nc <= w + 1))
                    continue;
                if (board[nr][nc] == '*')
                    continue;
                if (is_visited(key, vst[nr][nc]))
                    continue;
                if (isupper(board[nr][nc]))
                {
                    if ((key & (1 << (board[nr][nc] - 'A'))))
                        board[nr][nc] = '.';
                    else
                        continue;
                }
                if (islower(board[nr][nc]))
                {
                    key |= (1 << (board[nr][nc] - 'a'));
                    board[nr][nc] = '.';
                }
                if (board[nr][nc] == '$')
                {
                    board[nr][nc] = '.';
                    ++res;
                }
                q.emplace(nr, nc, key);
                key |= vst[nr][nc];
                vst[nr][nc] |= key;
            }
        }
        cout << res << '\n';
    }
    return 0;
}