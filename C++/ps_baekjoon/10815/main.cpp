#include <bits/stdc++.h>
using namespace std;

constexpr int mxVAL = 1e7;
int n, m;
bool is_exist[2 * mxVAL + 1];

int idx(int num) { return num + mxVAL; }

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        is_exist[idx(num)] = true;
    }
    cin >> m;
    while (m--)
    {
        int num;
        cin >> num;
        cout << is_exist[idx(num)] << ' ';
    }
    return 0;
}