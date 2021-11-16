#include <bits/stdc++.h>
using namespace std;

constexpr int mxWH = 5e2, INF = numeric_limits<int>::max() / 2;
int w, h, n, board[mxWH + 2][mxWH + 2];
bool valid[mxWH + 2][mxWH + 2];
vector<int> res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> w >> h >> n;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
        {
            char input;
            cin >> input;
            if (input == 'X')
                continue;
            board[i][j] += (1 + board[i][j - 1]);
        }
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
        {
            if (board[i][j] == 0)
                continue;
            int row_length = 1;
            int col_length = board[i][j];
            for (int tmp = i; col_length <= board[tmp][j]; --tmp)
                valid[row_length++][col_length] = true;
            --row_length;
            for (int tmp = i; col_length <= board[tmp][j]; ++tmp)
                valid[row_length++][col_length] = true;
        }
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (valid[b][a])
            res.push_back(i);
    }
    cout << res.size() << '\n';
    for (const auto& e : res)
        cout << e << ' ';
    return 0;
}