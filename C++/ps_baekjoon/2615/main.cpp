#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 19;
array<array<char, SIZE + 2>, SIZE + 2> board;
array<array<int, SIZE + 2>, SIZE + 2> dp;

void clear_dp()
{
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            dp[i][j] = 0;
}

void check_horizontal(const char& color)
{
    clear_dp();
    for (int i = SIZE; i >= 1; --i)
        for (int j = SIZE; j >= 1; --j)
            if (board[i][j] == color)
            {
                dp[i][j] = dp[i][j + 1] + 1;
                if (dp[i][j] == 5 && board[i][j - 1] != color)
                {
                    cout << board[i][j] << '\n';
                    cout << i << ' ' << j;
                    exit(0);
                }
            }
}

void check_vertical(const char& color)
{
    clear_dp();
    for (int i = SIZE; i >= 1; --i)
        for (int j = SIZE; j >= 1; --j)
            if (board[i][j] == color)
            {
                dp[i][j] = dp[i + 1][j] + 1;
                if (dp[i][j] == 5 && board[i - 1][j] != color)
                {
                    cout << board[i][j] << '\n';
                    cout << i << ' ' << j;
                    exit(0);
                }
            }
}

void check_left_diagonal(const char& color)
{
    clear_dp();
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            if (board[i][j] == color)
            {
                dp[i][j] = dp[i - 1][j + 1] + 1;
                if (dp[i][j] == 5 && board[i + 1][j - 1] != color)
                {
                    cout << board[i][j] << '\n';
                    cout << i << ' ' << j;
                    exit(0);
                }
            }
}

void check_right_diagonal(const char& color)
{
    clear_dp();
    for (int i = SIZE; i >= 1; --i)
        for (int j = SIZE; j >= 1; --j)
            if (board[i][j] == color)
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                if (dp[i][j] == 5 && board[i - 1][j - 1] != color)
                {
                    cout << board[i][j] << '\n';
                    cout << i << ' ' << j;
                    exit(0);
                }
            }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            cin >> board[i][j];
    for (const auto& e : {'1', '2'})
    {
        check_horizontal(e);
        check_vertical(e);
        check_left_diagonal(e);
        check_right_diagonal(e);
    }
    cout << 0;
    return 0;
}