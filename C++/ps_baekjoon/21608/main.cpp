#include <bits/stdc++.h>
using namespace std;

constexpr int  dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, res;
vector<vector<int>> board;
unordered_map<int, unordered_set<int>> graph;
vector<int> order;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 2, vector<int>(n + 2));
    for (int i = 0; i < n * n; ++i)
    {
        int from;
        cin >> from;
        order.push_back(from);
        unordered_set<int> tmp;
        for (int j = 0; j < 4; ++j)
        {
            int to;
            cin >> to;
            tmp.insert(to);
        }
        graph[from] = move(tmp);
    }
    for (const auto& idx : order)
    {
        const auto& favorite = graph[idx];
        vector<tuple<int, int, int, int>> tmp;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (board[i][j])
                    continue;
                int blank = 0, prefer = 0;
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = i + dr[direction];
                    int nc = j + dc[direction];
                    if (!(1 <= nr && nr <= n && 1 <= nc && nc <= n))
                        continue;
                    if (board[nr][nc] == 0)
                        ++blank;
                    if (favorite.contains(board[nr][nc]))
                        ++prefer;
                    tmp.emplace_back(prefer, blank, i, j);
                }
            }
        sort(tmp.begin(), tmp.end(), [](const auto& a, const auto& b) {
            const auto& [a_prefer, a_blank, a_row, a_col] = a;
            const auto& [b_prefer, b_blank, b_row, b_col] = b;
            if (a_prefer == b_prefer)
                if (a_blank == b_blank)
                    if (a_row == b_row)
                        return a_col < b_col;
                    else
                        return a_row < b_row;
                else
                    return a_blank > b_blank;
            else
                return a_prefer > b_prefer;
        });
        const auto [prefer, blank, r, c] = tmp.front();
        board[r][c] = idx;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int cnt = 0;
            for (int direction = 0; direction < 4; ++direction)
            {
                int nr = i + dr[direction];
                int nc = j + dc[direction];
                if (graph[board[i][j]].contains(board[nr][nc]))
                    ++cnt;
            }
            res += pow(10, cnt - 1);
        }
    cout << res;
    return 0;
}
