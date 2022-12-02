#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, int> cnt;
stack<int> s, tmp;
vector<int> res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    res.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        ++cnt[num];
        s.push(num);
    }
    while (!s.empty())
    {
        auto now = s.top();
        s.pop();
        while (!tmp.empty() && cnt[tmp.top()] <= cnt[now])
            tmp.pop();
        res.push_back(tmp.empty() ? -1 : tmp.top());
        tmp.push(now);
    }
    for_each(res.rbegin(), res.rend(), [](const auto& e) {cout << e << ' '; });
    return 0;
}