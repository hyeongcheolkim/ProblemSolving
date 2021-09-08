#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool impossible = false;
        cin >> n;
        vector<vector<char>> board(n + 1, vector<char>(n + 1, '='));
        vector<bool> type(n + 1);
        for (int i = 1; i <= n; ++i)
            board[i][i] = 'X';
        for (int idx = 1; idx <= n; ++idx)
        {
            char num;
            cin >> num;
            if (num == '1')
                continue;
            type[idx] = true;
        }
        for (int idx = 1; idx <= n; ++idx)
            if (type[idx])
            {
                bool flag = true;
                for (int i = 1; i <= n; ++i)
                {
                    if (board[idx][i] == '=' && type[i])
                    {
                        board[idx][i] = '+';
                        board[i][idx] = '-';
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    impossible = true;
                    break;
                }
            }
        if (impossible)
            cout << "NO" << '\n';
        else
        {
            cout << "YES" << '\n';
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                    cout << board[i][j];
                cout << '\n';
            }
        }
    }
    return 0;
}