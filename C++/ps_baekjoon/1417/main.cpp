#include <bits/stdc++.h>
using namespace std;

int n, dasom, cnt;
priority_queue<int> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> dasom;
    for (int i = 0; i < n - 1; ++i)
    {
        int num;
        cin >> num;
        pq.emplace(num);
    }
    while (!pq.empty() && pq.top() >= dasom)
    {
        auto t = pq.top();
        pq.pop();
        if (t - 1 == 0)
            continue;
        pq.emplace(t - 1);
        ++dasom;
        ++cnt;
    }
    cout << cnt;
    return 0;
}