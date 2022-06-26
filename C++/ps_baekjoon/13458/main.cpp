#include <bits/stdc++.h>
using namespace std;

int n, b, c;
long long res;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> b >> c;
    for (auto ea : arr)
    {
        ea = max(0, ea - b);
        ++res;
        int q = ea / c;
        ea -= q * c;
        res += q;
        if (ea != 0)
            ++res;
    }
    cout << res;
    return 0;
}