#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int m, n, k;
vector<vector<bool>> board, vst;
vector<int> area;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n >> k;
    board.resize(m, decltype(board)::value_type(n));
    vst = board;
    while (k--)
    {
        int c1, r1, c2, r2;
        cin >> c1 >> r1 >> c2 >> r2;
        for (int c = c1; c < c2; ++c)
            for (int r = r1; r < r2; ++r)
                board[r][c] = true;
    }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j])
                continue;
            if (vst[i][j])
                continue;
            queue<pair<int, int>> q;
            vst[i][j] = true;
            int a = 1;
            q.emplace(i, j);
            while (!q.empty())
            {
                auto [r, c] = q.front();
                q.pop();
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = r + dr[direction];
                    int nc = c + dc[direction];
                    if (!(0 <= nr && nr < m && 0 <= nc && nc < n))
                        continue;
                    if (vst[nr][nc])
                        continue;
                    if (board[nr][nc])
                        continue;
                    vst[nr][nc] = true;
                    ++a;
                    q.emplace(nr, nc);
                }
            }
            area.push_back(a);
        }
    sort(area.begin(), area.end());
    cout << area.size() << '\n';
    for (const auto& e : area)
        cout << e << ' ';
    return 0;
}