#include <bits/stdc++.h>
using namespace std;

long long n, m, maxi_jewels;
vector<long long> jewels;

bool check(long long ea)
{
    long val = 0;
    for (const auto& e : jewels)
    {
        val += e / ea;
        if (e % ea)
            ++val;
    }
    return val <= n;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    jewels.reserve(m);
    while (m--)
    {
        long long val;
        cin >> val;
        jewels.push_back(val);
        maxi_jewels = max(maxi_jewels, val);
    }
    long long lt = 0;
    long long rt = maxi_jewels + 1;
    while (lt + 1 < rt)
    {
        long long mid = (lt + rt) / 2;
        if (check(mid))
            rt = mid;
        else
            lt = mid;
    }
    cout << rt;
    return 0;
}