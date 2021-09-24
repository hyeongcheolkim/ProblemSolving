#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e4;
int arr[mxN];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    if (next_permutation(arr, arr + n))
        for (int i = 0; i < n; ++i)
            cout << arr[i] << ' ';
    else
        cout << -1;
    return 0;
}