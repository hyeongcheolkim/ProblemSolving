#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5;
int n, cnt;
bool fx[mxN + 1], fy[mxN + 1];
vector<long long> vx, vy;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vx.resize(n);
    vy.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vx[i];
        vx[i] *= (i + 1);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> vy[i];
        vy[i] *= (i + 1);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < n && idx2 < n)
    {
        if (vx[idx1] == vy[idx2])
        {
            ++cnt;
            ++idx1;
            ++idx2;
        }
        else if (vx[idx1] > vy[idx2])
            ++idx2;
        else if (vx[idx1] < vy[idx2])
            ++idx1;
    }
    cout << cnt;
    return 0;
}