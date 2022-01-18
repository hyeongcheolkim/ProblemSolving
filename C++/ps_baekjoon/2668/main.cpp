#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, res;
vector<bool> vst;

void dfs(int start, int num)
{
    if (vst[num])
    {
        if (start == num)
            res.push_back(num);
    }
    else
    {
        vst[num] = true;
        dfs(start, arr[num]);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        vst.assign(n + 1, false);
        dfs(i, i);
    }
    cout << res.size() << '\n';
    for (const auto& e : res)
        cout << e << '\n';
    return 0;
}