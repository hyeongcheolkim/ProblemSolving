#include <bits/stdc++.h>
using namespace std;

int n, l, r, x, cnt;
vector<int> arr;
vector<bool> vst;

void dfs(int idx = 0)
{
    if (idx == n)
    {
        vector<int> p;
        for (int i = 0; i < n; ++i)
            if (vst[i])
                p.push_back(arr[i]);
        sort(p.begin(), p.end());
        auto sum = reduce(p.begin(), p.end(), 0, plus<int>());
        if (p.empty())
            return;
        if (sum < l)
            return;
        if (sum > r)
            return;
        if (p.back() - p.front() < x)
            return;
        ++cnt;
        return;
    }
    dfs(idx + 1);
    vst[idx] = true;
    dfs(idx + 1);
    vst[idx] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l >> r >> x;
    arr.resize(n);
    vst.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    dfs();
    cout << cnt;
    return 0;
}