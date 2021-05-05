//baekjoon ps 2178

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

struct pos
{
    int row;
    int col;
    int cnt;
    pos(const int &row, const int &col, const int &cnt)
    {
        this->row = row;
        this->col = col;
        this->cnt = cnt;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    int drow[] = {0, 0, -1, +1};
    int dcol[] = {-1, +1, 0, 0};
    cin >> n >> m;
    vector<vector<bool>> map(n + 2, vector<bool>(m + 2, 0));
    vector<vector<bool>> check(n + 2, vector<bool>(m + 2, 0));
    queue<pos> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            static char temp;
            cin >> temp;
            if (temp == '1')
                map[i][j] = true;
        }
    check[1][1] = true;
    q.push(pos(1, 1, 1));
    while (!q.empty())
    {
        static int row, col, cnt;
        row = q.front().row;
        col = q.front().col;
        cnt = q.front().cnt;
        if (row == n && col == m)
            break;
        q.pop();
        for (int dx = 0; dx < 4; dx++)
            if (map[row + drow[dx]][col + dcol[dx]] && !check[row + drow[dx]][col + dcol[dx]])
            {
                q.push(pos(row + drow[dx], col + dcol[dx], cnt + 1));
                check[row + drow[dx]][col + dcol[dx]] = true;
            }
    }
    cout << q.front().cnt;
    return 0;
}