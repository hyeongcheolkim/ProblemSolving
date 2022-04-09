#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e3;
int n, k, cnt, gold[mxN + 1], silver[mxN + 1], bronze[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int country;
        cin >> country;
        cin >> gold[country] >> silver[country] >> bronze[country];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (gold[i] > gold[k])
            ++cnt;
        else if (gold[i] == gold[k])
            if (silver[i] > silver[k])
                ++cnt;
            else if (silver[i] == silver[k])
                if (bronze[i] > bronze[k])
                    ++cnt;
    }
    cout << cnt + 1;
    return 0;
}