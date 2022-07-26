#include <bits/stdc++.h>
using namespace std;

int n, oper;
vector<bool> vst;
vector<long long> cache;

long long fac(long long num)
{
    if (cache[num] != 0)
        return cache[num];
    if (num == 1 || num == 0)
        return 1;
    return cache[num] = num * fac(num - 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> oper;
    cache.resize(n + 1);
    vst.resize(n + 1);
    if (oper == 1)
    {
        long long k;
        cin >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (vst[j])
                    continue;
                if (k > fac(n - i - 1))
                    k -= fac(n - i - 1);
                else
                {
                    arr[i] = j;
                    vst[j] = true;
                    break;
                }
            }
        for (const auto& e : arr)
            cout << e << ' ';
    }
    else if (oper == 2)
    {
        vector<int> input(n);
        for (int i = 0; i < n; ++i)
            cin >> input[i];
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < input[i]; ++j)
            {
                if (vst[j])
                    continue;
                cnt += fac(n - i - 1);
            }
            vst[input[i]] = true;
        }
        cout << cnt + 1;
    }
    return 0;
}

