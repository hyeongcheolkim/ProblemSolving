//baekjoon ps 7576

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

struct pos
{
    int r;
    int c;
    pos(const int &r, const int &c)
    {
        this->r = r;
        this->c = c;
    }
    bool isvalid(const int &r, const int &c)
    {
        return 0 <= this->r && this->r < r && 0 <= this->c && this->c < c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int r, c;
    int res = 1;
    int dr[] = {0, 0, -1, +1};
    int dc[] = {-1, +1, 0, 0};
    cin >> c >> r;
    int sum = 0;
    int cnt = r * c;
    vector<vector<int>> map(r, vector<int>(c));
    vector<vector<int>> check(r, vector<int>(c,0));
    queue<pos> q;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                q.push(pos(i, j));
                check[i][j] = 1;
            }
            else if (map[i][j] == -1)
                cnt--;
        }
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            static pos temp(0, 0);
            temp = pos(q.front().r + dr[i], q.front().c + dc[i]);
            if (temp.isvalid(r, c) && check[temp.r][temp.c]==0 && map[temp.r][temp.c]!=-1)
            {
                q.push(temp);
                check[temp.r][temp.c] = check[q.front().r][q.front().c] + 1;
            }
        }
        if (map[q.front().r][q.front().c] == 0)
        {
            map[q.front().r][q.front().c] = 1;
            res = max(res,check[q.front().r][q.front().c]);
        }
        q.pop();
    }
    for (const auto &e : map)
        for (const auto &e : e)
            if (e == 1)
                sum += 1;
    if (sum == cnt)
        cout << res-1;
    else
        cout << -1;
    return 0;
}