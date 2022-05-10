#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<vector<bool>> ban;

void dfs(int level = 0, int idx = 1)
{
    static vector<int> tmp;
    if (level == 3)
    {
        ++cnt;
        return;
    }
    for (int i = idx; i <= n; ++i)
    {
        if (!tmp.empty() && (ban[i][tmp.front()] || ban[i][tmp.back()]))
            continue;
        tmp.push_back(i);
        dfs(level + 1, i + 1);
        tmp.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    ban.resize(n + 1, vector<bool>(n + 1));
    while (m--)
    {
        int ice1, ice2;
        cin >> ice1 >> ice2;
        ban[ice1][ice2] = ban[ice2][ice1] = true;
    }
    dfs();
    cout << cnt;
    return 0;
}