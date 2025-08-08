#include <bits/stdc++.h>
using namespace std;

int h, w, x, y;
vector<vector<int>> mat;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w >> x >> y;
    int row_size = h + x;
    int col_size = w + y;
    mat.resize(row_size, vector<int>(col_size, 0));

    for (int i = 0; i < row_size; ++i)
        for (int j = 0; j < col_size; ++j)
            cin >> mat[i][j];

    for (int i = x; i < h; ++i)
    {
        for (int j = y; j < w; ++j)
        {
            mat[i][j] -= mat[i - x][j - y];
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}