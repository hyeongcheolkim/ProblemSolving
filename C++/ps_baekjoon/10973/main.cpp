#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    if (prev_permutation(arr.begin(), arr.end()))
        for (const auto& e : arr)
            cout << e << ' ';
    else
        cout << -1;
    return 0;
}