#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> cost;

bool check(long long num)
{
    long long cnt = 0;
    for (const auto& e : cost)
        cnt += num / e;
    return cnt >= m;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    cost.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    sort(cost.begin(), cost.end());
    long long lt = -1;
    long long rt = cost.back() * m + 1;
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