#include <bits/stdc++.h>
using namespace std;

int n, m, k, mini = numeric_limits<int>::max();
vector<vector<int>> val;
vector<tuple<int, int, int>> oper;
class Matrix;
vector<int> permu;

class Matrix
{
private:
    vector<vector<int>> data;
public:
    Matrix(const vector<vector<int>>& data) : data{move(data)} {}

    void rotate_clock(int row, int col, int weight)
    {
        for (int w = 1; w <= weight; ++w)
        {
            int tmp = data[row - w][col - w];
            for (int i = 0; i < 2 * w; ++i)
                data[row - w + i][col - w] = data[row - w + i + 1][col - w];
            swap(tmp, data[row - w][col - w]);
            for (int i = 0; i < 2 * w; ++i)
                data[row + w][col - w + i] = data[row + w][col - w + i + 1];
            for (int i = 0; i < 2 * w; ++i)
                data[row + w - i][col + w] = data[row + w - i - 1][col + w];
            for (int i = 0; i < 2 * w; ++i)
                data[row - w][col + w - i] = data[row - w][col + w - i - 1];
            swap(tmp, data[row - w][col - w]);
        }
    }

    void rotate_counter_clock(int row, int col, int weight)
    {
        for (int w = 1; w <= weight; ++w)
        {
            int tmp = data[row - w][col - w];
            for (int i = 0; i < 2 * w; ++i)
                data[row - w][col - w + i] = data[row - w][col - w + i + 1];
            swap(tmp, data[row - w][col - w]);
            for (int i = 0; i < 2 * w; ++i)
                data[row - w + i][col + w] = data[row - w + i + 1][col + w];
            for (int i = 0; i < 2 * w; ++i)
                data[row + w][col + w - i] = data[row + w][col + w - i - 1];
            for (int i = 0; i < 2 * w; ++i)
                data[row + w - i][col - w] = data[row + w - i - 1][col - w];
            swap(tmp, data[row - w][col - w]);
        }
    }
    int get_mat_val()
    {
        int ret = numeric_limits<int>::max();
        for (int i = 1; i < data.size(); ++i)
            ret = min(ret, reduce(data[i].begin() + 1, data[i].end(), 0, plus<int>()));
        return ret;
    }
};

void dfs(Matrix& mat, int level = 0)
{
    if (level == permu.size())
    {
        mini = min(mini, mat.get_mat_val());
        return;
    }
    auto [row, col, weight] = oper[permu[level]];
    mat.rotate_clock(row, col, weight);
    dfs(mat, level + 1);
    mat.rotate_counter_clock(row, col, weight);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    val.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> val[i][j];
    oper.reserve(k);
    permu.resize(k);
    iota(permu.begin(), permu.end(), 0);
    while (k--)
    {
        int r, c, s;
        cin >> r >> c >> s;
        oper.emplace_back(r, c, s);
    }
    Matrix mat{val};
    do { dfs(mat); } while (next_permutation(permu.begin(), permu.end()));
    cout << mini;
    return 0;
}