//baekjoon ps 1300

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll lt, rt, mid, res;
    lt = 1;
    rt = k;
    while (lt <= rt)
    {
        ll mid = (lt + rt) / 2;
        ll num = 0;
        for (ll i = 1; i <= n; i++)
            num += min(mid / i, n);
        if (num < k)
            lt = mid + 1;
        else
        {
            res = mid;
            rt = mid - 1;
        }
    }
    cout << res;
    return 0;
}