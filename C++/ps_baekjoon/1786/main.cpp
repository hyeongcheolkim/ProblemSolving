#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> dp, res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    getline(cin, t);
    getline(cin, p);
    int t_size = t.size(), p_size = p.size(), dp_size = p.size();
    dp.resize(dp_size);
    for (int i = 1, j = 0; i < dp_size; ++i)
    {
        while (j > 0 && p[i] != p[j])
            j = dp[j - 1];
        if (p[i] == p[j])
            dp[i] = ++j;
    }
    for (int i = 0, j = 0; i < t_size; ++i)
    {
        while (j > 0 && t[i] != p[j])
            j = dp[j - 1];
        if (t[i] == p[j])
        {
            if (j + 1 == p_size)
            {
                res.push_back(i - p_size + 1 + 1);
                j = dp[j];
            }
            else
                ++j;
        }
    }
    cout << res.size() << '\n';
    for (const auto& e : res)
        cout << e << ' ';
    return 0;
}