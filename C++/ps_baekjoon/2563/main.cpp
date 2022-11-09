#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 100;
int n, cnt;
vector<vector<bool>> paper;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    paper.resize(SIZE + 1, vector<bool>(SIZE + 1));
    cin >> n;
    while (n--)
    {
        int row, col;
        cin >> col >> row;
        for (int i = row; i < row + 10; ++i)
            for (int j = col; j < col + 10; ++j)
                paper[i][j] = true;
    }
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            cnt += paper[i][j];
    cout << cnt;
    return 0;
}