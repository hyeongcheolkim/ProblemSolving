#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        vector<bool> arr(n);
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            arr[i] = static_cast<bool>(num % 2);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            int j = i + 1;
            while (j < n && arr[i] == arr[j])
                ++j;
            if (j == n)
            {
                cnt = -1;
                break;
            }
            cnt += (j - i - 1);
            arr[i + 1] = !arr[i + 1];
            arr[j] = !arr[j];
        }
        cout << cnt << '\n';
    }
    return 0;
}