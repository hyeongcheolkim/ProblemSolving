#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

void dfs(int level = 0, int idx = 0)
{
    static vector<int> tmp;
    if (level == m)
    {
        for (const auto& e : tmp)
            cout << e << ' ';
        cout << '\n';
        return;
    }
    int prev = -1;
    for (int i = idx; i < n; ++i)
    {
        if (arr[i] == prev)
            continue;
        prev = arr[i];
        tmp.push_back(arr[i]);
        dfs(level + 1, i + 1);
        tmp.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    dfs();
    return 0;
}