#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{+1, 0, -1, 0}, dc[]{0, +1, 0, -1};
int n, m, r;
vector<vector<int>> mat;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> r;
    mat.resize(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    while (r--)
    {
        int row_begin = 1, col_begin = 1;
        while (row_begin != n / 2 + 1 && col_begin != m / 2 + 1)
        {
            int row_end = n + 1 - row_begin;
            int col_end = m + 1 - col_begin;
            int tmp = mat[row_begin][col_begin];
            for (int i = col_begin; i < col_end; ++i)
                mat[row_begin][i] = mat[row_begin][i + 1];
            for (int i = row_begin; i < row_end; ++i)
                mat[i][col_end] = mat[i + 1][col_end];
            for (int i = col_end; i > col_begin; --i)
                mat[row_end][i] = mat[row_end][i - 1];
            swap(tmp, mat[row_begin][col_begin]);
            for (int i = row_end; i > row_begin; --i)
                mat[i][col_begin] = mat[i - 1][col_begin];
            swap(tmp, mat[row_begin][col_begin]);
            ++row_begin;
            ++col_begin;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}