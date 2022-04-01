#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> swch;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    swch.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> swch[i];
    cin >> m;
    while (m--)
    {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1)
        {
            for (int i = num; i <= n; i += num)
                swch[i] = !swch[i];
        }
        if (gender == 2)
        {
            int lt = num;
            int rt = num;
            while (1 <= lt && rt <= n && swch[lt] == swch[rt])
            {
                --lt;
                ++rt;
            }
            for (int i = lt + 1; i < rt; ++i)
                swch[i] = !swch[i];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << swch[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
    return 0;
}