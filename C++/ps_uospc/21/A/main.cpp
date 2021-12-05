#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e2;
int n, arr[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 1; !idx1 || !idx2; ++i)
    {
        if (idx1 && !idx2 && arr[i] != -1)
            idx2 = i;
        if (!idx1 && arr[i] != -1)
            idx1 = i;
    }
    int d = (arr[idx2] - arr[idx1]) / (idx2 - idx1);
    int init = arr[idx1] - d * (idx1 - 1);
    for (int i = 0; i < n; ++i)
        cout << init + d * i << '\n';
    return 0;
}