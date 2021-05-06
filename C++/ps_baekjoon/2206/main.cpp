//baekjoon ps 2206

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    short r;
    short c;
    int cnt;
    bool isbreak;

    pos() {}
    pos(const short &r, const short &c, const int &cnt, const bool &isbreak)
    {
        this->r = r;
        this->c = c;
        this->cnt = cnt;
        this->isbreak = isbreak;
    }
    bool isvalid(const short &r, const short &c)
    {
        return 1 <= this->r && this->r <= r && 1 <= this->c && this->c <= c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    short n, m;
    bool flag = false;
    cin >> n >> m;
    vector<vector<bool>> map(n + 2, vector<bool>(m + 2, 1));
    vector<vector<vector<bool>>> check(n + 2, vector<vector<bool>>(m + 2, vector<bool>(2, false)));
    queue<pos> q;
    short dr[] = {0, 0, -1, +1};
    short dc[] = {-1, +1, 0, 0};
    for (short i = 1; i <= n; i++)
        for (short j = 1; j <= m; j++)
        {
            static char input;
            cin >> input;
            map[i][j] = input == '1' ? 1 : 0;
        }
    q.push(pos(1, 1, 1, false));
    check[1][1][0] = true;
    while (!q.empty())
    {
        if (q.front().r == n && q.front().c == m)
        {
            flag = true;
            break;
        }
        static pos front;
        front = q.front();
        q.pop();
        for (short i = 0; i < 4; i++)
        {
            static pos temp;
            temp = pos(front.r + dr[i], front.c + dc[i], front.cnt + 1, front.isbreak);
            if (temp.isvalid(n, m) && (temp.isbreak ? !check[temp.r][temp.c][1] : !check[temp.r][temp.c][0]))
                switch ((char)map[temp.r][temp.c])
                {
                case 0:
                    q.push(temp);
                    if (!temp.isbreak)
                        check[temp.r][temp.c][0] = true;
                    else
                        check[temp.r][temp.c][1] = true;
                    break;
                case 1:
                    if (!temp.isbreak)
                    {
                        temp.isbreak = true;
                        q.push(temp);
                    }
                    if (!temp.isbreak)
                        check[temp.r][temp.c][0] = true;
                    else
                        check[temp.r][temp.c][1] = true;
                    break;
                default:
                    break;
                }
        }
    }
    if (flag)
        cout << q.front().cnt;
    else
        cout << -1;
    return 0;
}