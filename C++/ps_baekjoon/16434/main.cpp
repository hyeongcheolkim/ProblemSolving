#include <bits/stdc++.h>
using namespace std;

int n, atk;
vector<tuple<int, int, int>> arr;

bool condition(const long long max_hp)
{
    long long _atk = atk;
    long long now_hp = max_hp;
    for (const auto &[t, a, h] : arr)
    {
        if (t == 1)
        {
            long long turn = h / _atk + ((h % _atk) == 0 ? 0 : 1);
            now_hp -= (turn - 1) * a;
            if (now_hp <= 0)
                return false;
        }
        if (t == 2)
        {
            _atk += a;
            now_hp = min(max_hp, now_hp + h);
        }
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> atk;
    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int t, a, h;
        cin >> t >> a >> h;
        arr.emplace_back(t, a, h);
    }

    long long lt = 0l;
    long long rt = numeric_limits<long long>::max() / 2;

    while (lt + 1 < rt)
    {
        long long mid = (rt - lt) / 2 + lt;
        if(condition(mid))
        {
            rt = mid;
        }
        else
        {
            lt = mid;
        }
    }
    cout << rt;
    return 0;
}