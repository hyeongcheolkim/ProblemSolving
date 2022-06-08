#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e6;
int arr[mxN * 2 + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        ++arr[num + mxN];
    }
    for (int i = 0; i <= 2 * mxN; ++i)
        while (arr[i]--)
            cout << i - mxN << '\n';
    return 0;
}