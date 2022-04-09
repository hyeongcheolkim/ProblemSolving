#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;

vector<vector<char>> mat1, mat2;

void reverse_element(int row, int col)
{
    for (int i = row; i <= row + 2; ++i)
        for (int j = col; j <= col + 2; ++j)
            mat1[i][j] = (mat1[i][j] == '0' ? '1' : '0');
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (auto& e : {&mat1, &mat2})
        e->resize(n + 1, vector<char>(m + 1));
    for (auto& e : {&mat1, &mat2})
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> (*e)[i][j];
    for (int i = 1; i <= n - 2; ++i)
        for (int j = 1; j <= m - 2; ++j)
            if (mat1[i][j] != mat2[i][j])
            {
                reverse_element(i, j);
                ++cnt;
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mat1[i][j] != mat2[i][j])
            {
                cout << -1;
                exit(0);
            }
    cout << cnt;
    return 0;
}