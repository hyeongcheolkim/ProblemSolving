#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for_each(arr.begin(), arr.end(), [](auto& e) {e = abs(e - s); });
    cout << reduce(arr.begin(), arr.end(), arr.front(), [](auto a, auto& b) {return gcd(a, b); });
    return 0;
}