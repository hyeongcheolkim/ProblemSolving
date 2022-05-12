#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
map<int, bool> vst;

void dfs(int max_level, int idx = 0, int level = 0, int sum = 0)
{
    if (max_level == level)
    {
        vst[sum] = true;
        return;
    }
    for (int i = idx; i < n; ++i)
        dfs(max_level, i + 1, level + 1, sum + arr[i]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
        dfs(i);
    int num = 1;
    while (vst[num])
        ++num;
    cout << num;
    return 0;
}