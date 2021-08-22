//baekjoon ps 3055

#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;
constexpr char OUT_OF_BOUND = 0;
constexpr int dr[] = {0, 0, +1, -1};
constexpr int dc[] = {+1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c;
    cin >> r >> c;
    vector<vector<char>> map(r + 2, vector<char>(c + 2, OUT_OF_BOUND));
    vector<vector<bool>> s_visit(r + 2, vector<bool>(c + 2));
    vector<vector<bool>> w_visit(r + 2, vector<bool>(c + 2));
    queue<pair<pos, int>> s_q;
    queue<pair<pos, int>> w_q;
    pos D;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 'D')
                D = pos{i, j};
            if (map[i][j] == 'S')
            {
                s_q.emplace(pos{i, j}, 0);
                s_visit[i][j] = true;
                map[i][j] = '.';
            }
            if (map[i][j] == '*')
            {
                w_q.emplace(pos{i, j}, 0);
                w_visit[i][j] = true;
            }
        }
    for (int cnt = 0; !s_q.empty(); ++cnt)
    {
        while (!w_q.empty())
        {
            auto [w_now_row, w_now_col] = w_q.front().first;
            int now_cnt = w_q.front().second;
            if (cnt != now_cnt)
                break;
            w_q.pop();
            for (int direction = 0; direction < sizeof(dr) / sizeof(int); ++direction)
            {
                int w_next_row = w_now_row + dr[direction];
                int w_next_col = w_now_col + dc[direction];
                if (map[w_next_row][w_next_col] == OUT_OF_BOUND || w_visit[w_next_row][w_next_col])
                    continue;
                if (map[w_next_row][w_next_col] == '.')
                {
                    w_q.emplace(pos{w_next_row, w_next_col}, now_cnt + 1);
                    w_visit[w_next_row][w_next_col] = true;
                    map[w_next_row][w_next_col] = '*';
                }
            }
        }
        while (!s_q.empty())
        {
            auto [s_now_row, s_now_col] = s_q.front().first;
            int now_cnt = s_q.front().second;
            if (cnt != now_cnt)
                break;
            s_q.pop();
            for (int direction = 0; direction < sizeof(dr) / sizeof(int); ++direction)
            {
                int s_next_row = s_now_row + dr[direction];
                int s_next_col = s_now_col + dc[direction];
                if (map[s_next_row][s_next_col] == OUT_OF_BOUND || s_visit[s_next_row][s_next_col])
                    continue;
                if (map[s_next_row][s_next_col] == 'D')
                {
                    cout << now_cnt + 1;
                    exit(0);
                }
                if (map[s_next_row][s_next_col] == '.')
                {
                    s_q.emplace(pos{s_next_row, s_next_col}, now_cnt + 1);
                    s_visit[s_next_row][s_next_col] = true;
                }
            }
        }
    }
    cout << "KAKTUS";
    return 0;
}