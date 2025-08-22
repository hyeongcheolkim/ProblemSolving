#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<vector<int>> mem;
int k;
const int INF = numeric_limits<int>::max()/2;

int dp(int lt, int rt)
{
    int &ret = mem[lt][rt];
    if (ret != -1)
        return ret;
    if(lt + 1 == rt)
        return ret = 0;
    if(lt + 2 == rt)
        return ret = arr[lt] + arr[lt + 1];
    ret = INF;

    for (int i = 0; i < k; ++i)
    {
        ret = min(ret, dp(0, i) + dp(i, k));
    }
    return ret;
}

void solve()
{
    cin >> k;
    arr.assign(k, 0);
    mem.assign(k, vector<int>(k, -1));

    for (int i = 0; i < k; ++i)
        cin >> arr[i];

    cout << dp(0, k) << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}