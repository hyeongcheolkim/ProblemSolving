#include <bits/stdc++.h>
using namespace std;

constexpr int mxC = 1e9;
int n, m, res;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    arr.resize(n);
    int lt = 1, rt = mxC;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        lt = max(lt, arr[i]);
    }
    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;
        int cnt = 0;
        int remain = 0;
        for (const auto& e : arr)
        {
            if (remain < e)
            {
                remain = mid;
                ++cnt;
            }
            remain -= e;
        }
        if (cnt > m)
            lt = mid + 1;
        else if (cnt <= m)
        {
            res = mid;
            rt = mid - 1;
        }
    }
    cout << res;
    return 0;
}