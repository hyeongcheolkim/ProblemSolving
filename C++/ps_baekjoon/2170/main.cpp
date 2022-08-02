#include <bits/stdc++.h>
using namespace std;

int n, len = 0;
deque<pair<int, int>> dq;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        dq.emplace_back(x, y);
    }
    sort(dq.begin(), dq.end());
    while (dq.size() >= 2)
    {
        auto [first_x, first_y] = dq.front();
        dq.pop_front();
        auto [second_x, second_y] = dq.front();
        dq.pop_front();
        if (first_x <= second_x && second_x <= first_y && first_y <= second_y)
            dq.emplace_front(first_x, second_y);
        else if (first_x <= second_x && second_x <= first_y && second_y <= first_y)
            dq.emplace_front(first_x, first_y);
        else if (first_y <= second_x)
        {
            q.emplace(first_x, first_y);
            dq.emplace_front(second_x, second_y);
        }
    }
    q.emplace(dq.back());
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        len += (y - x);
    }
    cout << len;
    return 0;
}