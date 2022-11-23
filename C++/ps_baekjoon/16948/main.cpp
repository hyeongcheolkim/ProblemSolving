#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{-2, -2, 0, 0, +2, +2}, dc[]{-1, +1, -2, +2, -1, +1};
constexpr int INF = numeric_limits<int>::max() / 2;
int n, r1, c1, r2, c2;
vector<vector<int>> vst;
queue<pair<int, int>> q;

bool is_out_of_bound(int row, int col) { return !(0 <= row && row < n && 0 <= col && col < n); }

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vst.resize(n, decltype(vst)::value_type(n, INF));
    cin >> r1 >> c1 >> r2 >> c2;
    vst[r1][c1] = 0;
    q.emplace(r1, c1);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        int now_move_cnt = vst[r][c];
        q.pop();
        for (int direction = 0; direction < 6; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (is_out_of_bound(nr, nc))
                continue;
            if (now_move_cnt + 1 < vst[nr][nc])
            {
                vst[nr][nc] = now_move_cnt + 1;
                q.emplace(nr, nc);
            }
        }
    }
    cout << (vst[r2][c2] == INF ? -1 : vst[r2][c2]);
    return 0;
}