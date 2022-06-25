#include <bits/stdc++.h>
using namespace std;

string s, p;
vector<int> dp;

void make_table()
{
    dp.resize(p.size());
    for (int i = 1, j = 0; i < dp.size(); ++i)
    {
        while (j > 0 && p[i] != p[j])
            j = dp[j - 1];
        if (p[i] == p[j])
            dp[i] = ++j;
    }
}

bool kmp()
{
    for (int i = 0, j = 0; i < s.size(); ++i)
    {
        while (j > 0 && s[i] != p[j])
            j = dp[j - 1];
        if (s[i] == p[j])
        {
            if (j + 1 == p.size())
                return true;
            else
                ++j;
        }
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> p;
    make_table();
    cout << kmp();
    return 0;
}