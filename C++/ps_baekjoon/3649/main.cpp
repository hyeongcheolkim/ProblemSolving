#include <bits/stdc++.h>
using namespace std;

int x;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> x)[&]
    {
        x *= 1e7;
        int n;
        cin >> n;
        vector<int> blocks(n);
        for (int i = 0; i < n; ++i)
            cin >> blocks[i];
        sort(blocks.begin(), blocks.end());
        int lt = 0;
        int rt = blocks.size() - 1;
        while (lt < rt)
        {
            if (auto sum = blocks[lt] + blocks[rt]; sum == x)
            {
                cout << "yes" << ' ' << blocks[lt] << ' ' << blocks[rt] << '\n';
                return;
            }
            else if (sum < x)
                ++lt;
            else if (sum > x)
                --rt;
        }
        cout << "danger" << '\n';
    }();
    return 0;
}