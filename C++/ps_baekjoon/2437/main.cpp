//baekjoon ps 2437

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    int idx = 0, res = sum + 1;
    for (const auto &weight : arr)
    {
        if ((idx + 1) - weight < 0)
        {
            res = idx + 1;
            break;
        }
        idx += weight;
    }
    cout << res;
    return 0;
}