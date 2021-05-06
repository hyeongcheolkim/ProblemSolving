//baekjoon ps 1697

#include <iostream>
#include <queue>

using namespace std;

struct pos
{
    int x;

    pos(const int &x)
    {
        this->x = x;
    }
    pos walk_back()
    {
        return pos(x - 1);
    }
    pos walk_front()
    {
        return pos(x + 1);
    }
    pos teleport()
    {
        return pos(2 * x);
    }
    bool operator==(const int &num) const
    {
        return this->x == num;
    }
    bool isvalid()
    {
        return 0 <= x && x <= 100000;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    queue<pos> q;
    vector<int> check(100000 + 1, 0);
    q.push(pos(n));
    check[n] = 1;
    while (true)
    {
        if (q.front() == k)
            break;
        if (q.front().walk_back().isvalid() && !check[q.front().walk_back().x])
        {
            q.push(q.front().walk_back());
            check[q.front().walk_back().x] = check[q.front().x] + 1;
        }
        if (q.front().walk_front().isvalid() && !check[q.front().walk_front().x])
        {
            q.push(q.front().walk_front());
            check[q.front().walk_front().x] = check[q.front().x] + 1;
        }
        if (q.front().teleport().isvalid() && !check[q.front().teleport().x])
        {
            q.push(q.front().teleport());
            check[q.front().teleport().x] = check[q.front().x] + 1;
        }
        q.pop();
    }
    cout << check[q.front().x]-1;
    return 0;
}