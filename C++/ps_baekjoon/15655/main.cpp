#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

void dfs(int idx = 0, int level = 0)
{
    static vector<int> tmp;
    if (level == m)
    {
        for (const auto& e : tmp)
            cout << e << ' ';
        cout << '\n';
        return;
    }
    for (int i = idx; i < n; ++i)
    {
        tmp.push_back(arr[i]);
        dfs(i + 1, level + 1);
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