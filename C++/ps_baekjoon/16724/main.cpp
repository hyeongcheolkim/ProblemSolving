//baekjoon ps 16724

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pos = pair<int, int>;

vector<vector<pos>> uf;

pos find(pos data)
{
    int row = data.first;
    int col = data.second;
    if (uf[row][col] == data)
        return data;
    pos nextpos = find(uf[row][col]);
    return uf[row][col] = uf[nextpos.first][nextpos.second];
}

bool uni(pos a, pos b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        uf[a.first][a.second] = b;
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int cnt = n * m;
    vector<vector<char>> map(n + 2, vector<char>(m + 2, 0));
    uf = move(vector<vector<pos>>(n + 2, vector<pos>(m + 2)));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            uf[i][j] = {i, j};
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int nowrow = i;
            int nowcol = j;
            int nextrow;
            int nextcol;
            char direct = map[nowrow][nowcol];
            switch (direct)
            {
            case 'U':
                nextrow = nowrow - 1;
                nextcol = nowcol;
                break;
            case 'D':
                nextrow = nowrow + 1;
                nextcol = nowcol;
                break;
            case 'L':
                nextrow = nowrow;
                nextcol = nowcol - 1;
                break;
            case 'R':
                nextrow = nowrow;
                nextcol = nowcol + 1;
                break;
            default:
                break;
            }
            if (uni({nowrow, nowcol}, {nextrow, nextcol}))
                cnt--;
        }
    cout << cnt;
    return 0;
}
