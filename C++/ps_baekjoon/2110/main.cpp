#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> houses;
int ans = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> c;
    houses.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> houses[i];
    sort(houses.begin(), houses.end());
    int lt = 0;
    int rt = houses.back() - houses.front() + 1;
    while(lt + 1 < rt)
    {
        int mid  = (rt - lt) / 2 + lt;
        int cnt = 1;
        int last = houses[0];
        for (int i = 1; i < n; ++i)
        {
            if (houses[i] - last >= mid)
            {
                ++cnt;
                last = houses[i];
            }
        }
        if (cnt >= c)
        {
            ans = max(ans, mid);
            lt = mid;
        }
        else
            rt = mid;
    }
    cout << ans;
    return 0;
}