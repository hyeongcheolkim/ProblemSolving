#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, k, acc, maxi = -INF;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < k; ++i)
        acc += arr[i];
    maxi = max(maxi, acc);
    for (int i = k; i < n; ++i)
    {
        acc -= arr[i - k];
        acc += arr[i];
        maxi = max(maxi, acc);
    }
    cout << maxi;
    return 0;
}