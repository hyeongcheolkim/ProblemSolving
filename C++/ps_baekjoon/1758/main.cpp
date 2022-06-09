#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
long long res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < n; ++i)
        if (int tip = arr[i] - i; tip > 0)
            res += arr[i] - i;
        else
            break;
    cout << res;
    return 0;
}