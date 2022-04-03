#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];
    for (int i = 0; i < m; ++i)
        cin >> arr2[i];
    int cur1 = 0;
    int cur2 = 0;
    while (cur1 < n && cur2 < m)
    {
        if (arr1[cur1] < arr2[cur2])
            cout << arr1[cur1++] << ' ';
        else
            cout << arr2[cur2++] << ' ';
    }
    while (cur1 < n)
        cout << arr1[cur1++] << ' ';
    while (cur2 < m)
        cout << arr2[cur2++] << ' ';
    return 0;
}