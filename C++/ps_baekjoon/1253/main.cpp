#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i)
    {
        int val = arr[i];
        arr.erase(arr.begin() + i, arr.begin() + i + 1);
        int lt = 0;
        int rt = arr.size() - 1;
        while (lt < rt)
        {
            if (auto sum = arr[lt] + arr[rt]; sum == val)
            {
                ++cnt;
                break;
            }
            else if (sum < val)
                ++lt;
            else if (sum > val)
                --rt;
        }
        arr.insert(arr.begin() + i, val);
    }
    cout << cnt;
    return 0;
}