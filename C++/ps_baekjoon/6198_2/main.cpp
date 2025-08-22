#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int,int>> s;
unsigned long long ret = 0L;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int idx = 0; idx < n; ++idx)
    {
        int h;
        cin >> h;

        while(!s.empty() && s.top().second <= h)
        {
            ret += idx - s.top().first - 1;
            s.pop();
        }

        s.emplace(idx, h);
    }
    int last_idx = s.top().first;
    while(!s.empty())
    {
        ret += last_idx - s.top().first;
        s.pop();
    }
    cout << ret;
    return 0;
}