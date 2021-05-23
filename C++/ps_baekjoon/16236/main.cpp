//baekjoon ps 16236

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int r, c, dis;
    pos(const int &r, const int &c, const int &dis)
    {
        this->r = r;
        this->c = c;
        this->dis = dis;
    }
    bool operator<(const pos &obj) const
    {
        if (dis == obj.dis)
        {
            if (r == obj.r)
                return c > obj.c;
            else
                return r > obj.r;
        }
        else
            return dis > obj.dis;
    }
};

struct shark
{
    int r, c, s, ate;
    void sizeUp()
    {
        ate = 0;
        s++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int dr[4] = {-1, 0, 1, 0};
    constexpr int dc[4] = {0, 1, 0, -1};
    int n, res = 0;
    cin >> n;
    vector<vector<int>> map(n + 2, vector<int>(n + 2));
    vector<vector<bool>> check(n + 2, vector<bool>(n + 2));
    priority_queue<pos> pq;
    shark baby;
    baby.s = 2;
    baby.ate = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                pq.push(pos(i, j, 0));
                map[i][j] = 0;
            }
        }
    while (!pq.empty())
    {
        pos tmp = pq.top();
        pq.pop();
        int r = tmp.r;
        int c = tmp.c;
        int d = tmp.dis;
        if (map[r][c] != 0 && map[r][c] < baby.s)
        {
            baby.r = r;
            baby.c = c;
            baby.ate++;
            if (baby.ate == baby.s)
                baby.sizeUp();
            map[r][c] = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    check[i][j] = false;
            while (!pq.empty())
                pq.pop();
            res = d;
        }
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (1 <= nr && nr <= n && 1 <= nc && nc <= n && map[nr][nc] <= baby.s && !check[nr][nc])
            {
                pq.push(pos(nr, nc, d + 1));
                check[nr][nc] = true;
            }
        }
    }
    cout << res;
    return 0;
}