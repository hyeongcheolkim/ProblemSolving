//baekjoon ps 12851

#include <iostream>
#include <queue>

using namespace std;

struct pos
{
    int x;
    int num;

    pos(const int &x, const int &num)
    {
        this->x = x;
        this->num = num;
    }
    pos walk_back()
    {
        return pos(x - 1, this->num);
    }
    pos walk_front()
    {
        return pos(x + 1, this->num);
    }
    pos teleport()
    {
        return pos(2 * x, this->num);
    }
    pos timeup()
    {
        return pos(x, this->num + 1);
    }
    bool operator==(const int &integer) const
    {
        return this->x == integer;
    }
    bool isvalid()
    {
        return 0 <= x && x <= 100000;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, cnt = 0, res = 0;
    cin >> n >> k;
    queue<pos> q;
    vector<bool> check(100000 + 1);
    q.push(pos(n, 0));
    check[n] = true;
    while (!q.empty())
    {
        pos temp = q.front();
        q.pop();
        check[temp.x] = true;
        if (res && res == temp.num && temp == k)
            cnt++;
        if (!res && temp == k)
        {
            res = temp.num;
            cnt++;
        }
        if (temp.walk_back().isvalid() && !check[temp.walk_back().x])
            q.push(temp.walk_back().timeup());
        if (temp.walk_front().isvalid() && !check[temp.walk_front().x])
            q.push(temp.walk_front().timeup());
        if (temp.teleport().isvalid() && !check[temp.teleport().x])
            q.push(temp.teleport().timeup());
    }
    cout << res << '\n';
    cout << cnt;
    return 0;
}