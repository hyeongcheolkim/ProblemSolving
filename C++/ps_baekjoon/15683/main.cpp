#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, WALL = 6, CHECKED = 7, INF = numeric_limits<int>::max() / 2;
int n, m, mini = INF;
struct Direction;
struct CCTV;
vector<vector<int>> board;
vector<CCTV> cctv;
struct Direction
{
    bool up = false, down = false, left = false, right = false;
    Direction(int num)
    {
        switch (num)
        {
            case 1:
                right = true;
                break;
            case 2:
                left = right = true;
                break;
            case 3:
                up = right = true;
                break;
            case 4:
                up = left = right = true;
                break;
            case 5:
                up = left = right = down = true;
                break;
            default:
                break;
        }
    }
    void rotate_clock()
    {
        auto tmp = up;
        up = left;
        left = down;
        down = right;
        right = tmp;
    }
    void rotate_counter_colock()
    {
        auto tmp = up;
        up = right;
        right = down;
        down = left;
        left = tmp;
    }
    void rotate_reverse()
    {
        swap(left, right);
        swap(up, down);
    }
};

struct CCTV
{
    int row, col;
    Direction direction;
    CCTV(const int& row, const int& col, const int& num) :direction{num}
    {
        this->row = row;
        this->col = col;
    }
};

int calculate_area()
{
    int ret = 0;
    auto tmp = board;
    for (const auto& e : cctv)
    {
        const auto& direct = e.direction;
        if (direct.down)
        {
            int row = e.row;
            int col = e.col;
            while (tmp[row + 1][col] != OUT_OF_BOUND && tmp[row + 1][col] != WALL)
                tmp[++row][col] = CHECKED;
        }
        if (direct.up)
        {
            int row = e.row;
            int col = e.col;
            while (tmp[row - 1][col] != OUT_OF_BOUND && tmp[row - 1][col] != WALL)
                tmp[--row][col] = CHECKED;
        }
        if (direct.left)
        {
            int row = e.row;
            int col = e.col;
            while (tmp[row][col - 1] != OUT_OF_BOUND && tmp[row][col - 1] != WALL)
                tmp[row][--col] = CHECKED;
        }
        if (direct.right)
        {
            int row = e.row;
            int col = e.col;
            while (tmp[row][col + 1] != OUT_OF_BOUND && tmp[row][col + 1] != WALL)
                tmp[row][++col] = CHECKED;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (tmp[i][j] == 0)
                ++ret;
    return ret;
}

void dfs(int level = 0)
{
    if (level == cctv.size())
    {
        auto ret = calculate_area();
        mini = min(mini, ret);
        return;
    }
    auto& direct = cctv[level].direction;

    dfs(level + 1);

    direct.rotate_clock();
    dfs(level + 1);
    direct.rotate_counter_colock();

    direct.rotate_counter_colock();
    dfs(level + 1);
    direct.rotate_clock();

    direct.rotate_reverse();
    dfs(level + 1);
    direct.rotate_reverse();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(m + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != WALL)
                cctv.emplace_back(i, j, board[i][j]);
        }
    dfs();
    cout << mini;
    return 0;
}