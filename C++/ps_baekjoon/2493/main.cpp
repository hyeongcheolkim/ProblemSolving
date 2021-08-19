//baekjoon ps 2493

#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> res(n + 1);
    stack<pair<int, int>> s;
    s.emplace(0, INF);
    for (int now_idx = 1; now_idx <= n; ++now_idx)
    {
        int now_height;
        cin >> now_height;
        while (s.top().second <= now_height)
            s.pop();
        res[now_idx] = s.top().first;
        s.emplace(now_idx, now_height);
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
    return 0;
}