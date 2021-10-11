#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxNM = 50, NOT_VST = 0, dr[]{0, +1, 0, -1}, dc[]{+1, 0, -1, 0}, wall[]{1, 2, 4, 8};
int n, m, idx = 1, board[mxNM][mxNM], vst[mxNM][mxNM];
unordered_map<int, set<int>> graph;
unordered_map<int, int> room;
queue<pos> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!vst[i][j])
            {
                vst[i][j] = idx;
                int cnt = 1;
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
                        if (board[nr][nc] & wall[direction])
                        {
                            if (vst[nr][nc] && vst[nr][nc] != idx)
                                graph[idx].emplace(vst[nr][nc]);
                            continue;
                        }
                        if (vst[nr][nc])
                            continue;
                        vst[nr][nc] = idx;
                        q.emplace(nr, nc);
                        ++cnt;
                    }
                }
                room[idx] = cnt;
                ++idx;
            }
    int max_room = 0;
    int max_room_sum = -1;
    for (const auto& e : graph)
    {
        auto [room1, connect] = e;
        for (const auto& room2 : connect)
            max_room_sum = max(max_room_sum, room[room1] + room[room2]);
    }
    for (const auto& e : room)
        max_room = max(max_room, e.second);
    cout << room.size() << '\n' << max_room << '\n' << max_room_sum;
    return 0;
}