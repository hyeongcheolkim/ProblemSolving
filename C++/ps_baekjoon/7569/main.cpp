//baekjoon ps 7569

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

struct pos
{
    int h;
    int r;
    int c;
    pos(const int &h, const int &r, const int &c)
    {
        this->r = r;
        this->c = c;
        this->h = h;
    }
    bool isvalid(const int &h, const int &r, const int &c)
    {
        return 0 <= this->r && this->r < r && 0 <= this->c && this->c < c && 0 <= this->h && this->h < h;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int r, c, h;
    int res = 1;
    int dr[] = {0, 0, -1, +1, 0, 0};
    int dc[] = {-1, +1, 0, 0, 0, 0};
    int dh[] = {0, 0, 0, 0, -1, +1};
    cin >> c >> r >> h;
    int sum = 0;
    int cnt = r * c * h;
    vector<vector<vector<int>>> map(h, vector<vector<int>>(r, vector<int>(c, 0)));
    vector<vector<vector<int>>> check(h, vector<vector<int>>(r, vector<int>(c, 0)));
    queue<pos> q;

    for (int k = 0; k < h; k++)
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> map[k][i][j];
                if (map[k][i][j] == 1)
                {
                    q.push(pos(k, i, j));
                    check[k][i][j] = 1;
                }
                else if (map[k][i][j] == -1)
                    cnt--;
            }
    while (!q.empty())
    {
        for (int i = 0; i < 6; i++)
        {
            static pos temp(0, 0, 0);
            temp = pos(q.front().h + dh[i], q.front().r + dr[i], q.front().c + dc[i]);
            if (temp.isvalid(h, r, c) && check[temp.h][temp.r][temp.c] == 0 && map[temp.h][temp.r][temp.c] != -1)
            {
                q.push(temp);
                check[temp.h][temp.r][temp.c] = check[q.front().h][q.front().r][q.front().c] + 1;
            }
        }
        if (map[q.front().h][q.front().r][q.front().c] == 0)
        {
            map[q.front().h][q.front().r][q.front().c] = 1;
            res = max(res, check[q.front().h][q.front().r][q.front().c]);
        }
        q.pop();
    }
    for (const auto &e : map)
        for (const auto &e : e)
            for (const auto &e : e)
                if (e == 1)
                    sum += 1;
    if (sum == cnt)
        cout << res - 1;
    else
        cout << -1;
    return 0;
}