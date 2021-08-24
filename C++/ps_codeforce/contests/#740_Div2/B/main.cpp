#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        vector<int> res;
        pair<int, int> A, B;
        if (a < b)
            swap(a, b);
        if ((a + b) % 2 == 0)
        {
            int num = (a + b) / 2;
            for (int i = 0; i <= b; ++i)
                res.push_back(num - b + 2 * i);
        }
        else
        {
            int num = (a + b) / 2;
            for (int i = 0; i <= b; ++i)
                res.push_back(num - b + 2 * i);
            ++num;
            for (int i = 0; i <= b; ++i)
                res.push_back(num - b + 2 * i);
        }
        sort(res.begin(), res.end());
        cout << res.size() << '\n';
        for (int i = 0; i < res.size();++i)
            cout << res[i] << ' ';
        cout << '\n';
    }
    return 0;
}