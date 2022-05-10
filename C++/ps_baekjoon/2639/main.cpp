#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        array<int, 10> arr;
        for (int i = 0; i < 10; ++i)
            cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        cout << arr[2] << '\n';
    }
    return 0;
}