#include <bits/stdc++.h>
using namespace std;

int n, init_ball_ea, k, res;
struct ball;
vector<vector<vector<ball>>> board, tmp;
map<int, pair<int, int>> direct{
    {0, {-1, 0}},
    {1, {-1, +1}},
    {2, {0, +1}},
    {3, {+1, +1}},
    {4, {+1, 0}},
    {5, {+1, -1}},
    {6, {0, -1}},
    {7, {-1, -1}},
};

struct ball
{
    int m, s, d;
    ball(const int& m, const int& s, const int& d)
    {
        this->m = m;
        this->s = s;
        this->d = d;
    }
};

void command_move()
{
    tmp.assign(n + 1, vector<vector<ball>>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (const auto& [m, s, d] : board[i][j])
            {
                int row = i, col = j;
                const auto& [direct_r, direct_c] = direct[d];
                int dr = s * direct_r;
                int dc = s * direct_c;
                while (dr)
                {
                    if (dr < 0)
                    {
                        ++dr;
                        if (--row == 0)
                            row = n;
                    }
                    if (dr > 0)
                    {
                        --dr;
                        if (++row == n + 1)
                            row = 1;
                    }
                }
                while (dc)
                {
                    if (dc < 0)
                    {
                        ++dc;
                        if (--col == 0)
                            col = n;
                    }
                    if (dc > 0)
                    {
                        --dc;
                        if (++col == n + 1)
                            col = 1;
                    }
                }
                tmp[row][col].emplace_back(m, s, d);
            }
    tmp.swap(board);
}

void sum_and_divde()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (board[i][j].size() >= 2)
            {
                vector<ball> new_balls;
                int total_m = 0;
                int total_s = 0;
                int total_ea = 0;
                vector<int> direction;
                for (const auto& [m, s, d] : board[i][j])
                {
                    total_m += m;
                    total_s += s;
                    ++total_ea;
                    direction.push_back(d);
                }
                int new_m = total_m / 5;
                int new_s = total_s / total_ea;
                bool all_even = all_of(direction.begin(), direction.end(), [](auto& e) {return e % 2 == 0; });
                bool all_odd = all_of(direction.begin(), direction.end(), [](auto& e) {return e % 2 == 1; });
                if (new_m && (all_even || all_odd))
                    for (int i = 0; i < 8; i += 2)
                        new_balls.emplace_back(new_m, new_s, i);
                else if (new_m)
                    for (int i = 1; i < 8; i += 2)
                        new_balls.emplace_back(new_m, new_s, i);
                board[i][j] = move(new_balls);
            }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> init_ball_ea >> k;
    board.resize(n + 1, vector<vector<ball>>(n + 1));
    while (init_ball_ea--)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r][c].emplace_back(m, s, d);
    }
    while (k--)
    {
        command_move();
        sum_and_divde();
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (const auto& [m, s, d] : board[i][j])
                res += m;
    cout << res;
    return 0;
}