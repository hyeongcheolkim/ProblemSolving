#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    arr.reserve(n);
    while (n--)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int lt = 0, rt = arr.size() - 1;
    while (lt < rt)
    {
        int sum = arr[lt] + arr[rt];
        if (sum == m)
        {
            ++cnt;
            --rt;
        }
        else if (sum < m)
            ++lt;
        else if (sum > m)
            --rt;
    }
    cout << cnt;
    return 0;
}