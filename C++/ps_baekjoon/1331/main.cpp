#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> vst;
pair<int, int> start, previous;

pair<int, int> parse(string pos)
{
    int row = pos.front() - 'A' + 1;
    int col = pos.back() - '0';
    return {row, col};
}

bool is_valid_move(pair<int, int> previous, pair<int, int> now)
{
    const auto& [prev_row, prev_col] = previous;
    const auto& [now_row, now_col] = now;
    int row_diff = abs(prev_row - now_row);
    int col_diff = abs(prev_col - now_col);
    if (row_diff == 1 && col_diff == 2 || row_diff == 2 && col_diff == 1)
        return true;
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vst.resize(6 + 1, vector<bool>(6 + 1));
    for (int i = 0; i < 36; ++i)
    {
        string input;
        cin >> input;
        auto now = parse(input);
        if (previous == pair<int, int>{0, 0})
        {
            start = previous = now;
            continue;
        }
        if (vst[now.first][now.second] || !is_valid_move(previous, now))
        {
            cout << "Invalid";
            exit(0);
        }
        vst[now.first][now.second] = true;
        previous = now;
    }
    if (is_valid_move(previous, start))
        cout << "Valid";
    else
        cout << "Invalid";
    return 0;
}