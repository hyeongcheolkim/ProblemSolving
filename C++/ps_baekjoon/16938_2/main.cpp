#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, l, r, x, cnt;
vector<int> arr;

void dfs(int idx = 0, long long state = 0)
{
    if (idx == n)
    {
        int maxi = 0, mini = INF, sum = 0;
        for (int i = 0; i < n; ++i)
            if (state & (1L << i))
            {
                maxi = max(maxi, arr[i]);
                mini = min(mini, arr[i]);
                sum += arr[i];
            }
        if (sum < l)
            return;
        if (sum > r)
            return;
        if (maxi - mini < x)
            return;
        ++cnt;
        return;
    }
    long long next_state = state;
    dfs(idx + 1, next_state);
    next_state |= (1L << idx);
    dfs(idx + 1, next_state);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l >> r >> x;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    dfs();
    cout << cnt;
    return 0;
}