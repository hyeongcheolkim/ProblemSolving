#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    const auto cmp = [](const int &a, const int &b)
    { return a < b; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    while (n--)
    {
        int a;
        cin >> a;
        if (a == 0 && pq.empty())
        {
            cout << -1 << '\n';
        }
        if (a == 0 && !pq.empty())
        {
            cout << pq.top() << '\n';
            pq.pop();
        }
        if (a != 0)
        {
            int val;
            while (a--)
            {
                cin >> val;
                pq.push(val);
            }
        }
    }
    return 0;
}