#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e6;
bool arr[mxN * 2 + 1];
int n;

int index(int num) { return num + mxN; }

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        arr[index(num)] = true;
    }
    for (int i = mxN; i >= -mxN; --i)
        if (arr[index(i)])
            cout << i << '\n';
    return 0;
}