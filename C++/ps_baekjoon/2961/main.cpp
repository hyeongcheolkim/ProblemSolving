#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, mini = INF;
vector<pair<int, int>> taste;

void dfs(int max_level, int level = 0, int idx = 0)
{
    static vector<pair<int, int>> tmp;
    if (level == max_level)
    {
        int sour = 1;
        int bitter = 0;
        for (const auto& [s, b] : tmp)
        {
            sour *= s;
            bitter += b;
        }
        mini = min(mini, abs(sour - bitter));
        return;
    }
    for (int i = idx; i < n; ++i)
    {
        tmp.push_back(taste[i]);
        dfs(max_level, level + 1, i + 1);
        tmp.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    taste.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> taste[i].first >> taste[i].second;
    for (int i = 1; i <= n; ++i)
        dfs(i);
    cout << mini;
    return 0;
}