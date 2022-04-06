#include <bits/stdc++.h>
using namespace std;

int n;
string maxi = "0000000000";
string mini = "9999999999";
vector<char> sign;
vector<bool> vst;
vector<int> res;

void dfs(int level = 0)
{
    if (level == n + 1)
    {
        string str;
        for (const char& e : res)
        {
            char c = e + '0';
            str.push_back(c);
        }
        maxi = max(maxi, str);
        mini = min(mini, str);
        return;
    }
    if (res.empty())
        for (const auto& e : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
        {
            vst[e] = true;
            res.push_back(e);
            dfs(level + 1);
            res.pop_back();
            vst[e] = false;
        }
    else
    {
        if (sign[level - 1] == '>')
            for (const auto& e : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
                if (!vst[e] && res.back() > e)
                {
                    vst[e] = true;
                    res.push_back(e);
                    dfs(level + 1);
                    res.pop_back();
                    vst[e] = false;
                }
        if (sign[level - 1] == '<')
            for (const auto& e : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
                if (!vst[e] && res.back() < e)
                {
                    vst[e] = true;
                    res.push_back(e);
                    dfs(level + 1);
                    res.pop_back();
                    vst[e] = false;
                }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    sign.resize(n);
    vst.resize(10);
    for (int i = 0; i < n; ++i)
        cin >> sign[i];
    dfs();
    cout << maxi << '\n';
    cout << mini << '\n';
    return 0;
}