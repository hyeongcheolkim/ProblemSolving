#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, mini = INF, maxi = -INF;
vector<int> arr;
map<char, int> oper_ea;

void dfs(int level = 0, int val = 0)
{
    if (level == n)
    {
        maxi = max(maxi, val);
        mini = min(mini, val);
        return;
    }
    if (level == 0)
    {
        dfs(level + 1, val = arr[0]);
        return;
    }
    for (auto& [oper, ea] : oper_ea)
    {
        if (ea == 0)
            continue;
        switch (oper)
        {
            case '+':
                --ea;
                dfs(level + 1, val + arr[level]);
                ++ea;
                break;
            case '-':
                --ea;
                dfs(level + 1, val - arr[level]);
                ++ea;
                break;
            case '*':
                --ea;
                dfs(level + 1, val * arr[level]);
                ++ea;
                break;
            case '/':
                --ea;
                dfs(level + 1, val / arr[level]);
                ++ea;
                break;
            default:
                break;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (const auto& oper : {'+', '-', '*', '/'})
        cin >> oper_ea[oper];
    dfs();
    cout << maxi << '\n' << mini;
    return 0;
}