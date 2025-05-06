#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> cache;

int solve(int lt, int rt)
{
    int &ret = cache[lt][rt];
    if (ret != -1)
        return ret;
    if (lt == rt)
        return ret = 1;
    if (lt + 1 == rt && arr[lt] == arr[rt])
        return ret = 1;
    if (lt + 1 == rt && arr[lt] != arr[rt])
        return ret = 0;

    return ret = ((arr[lt] == arr[rt]) && solve(lt + 1, rt - 1));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n + 1);
    cache.resize(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    cin >> m;
    while(m--)
    {
        int lt, rt;
        cin >> lt >> rt;
        cout << solve(lt, rt) << '\n';
    }
    return 0;
}