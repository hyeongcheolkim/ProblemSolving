#include <bits/stdc++.h>
using namespace std;

constexpr array<char, 5> exist{'a', 'n', 't', 'i', 'c'};
int n, k, res;
vector<string> words;
string input;
bool vst['z' + 1];

int count()
{
    int cnt = 0;
    for (const auto& word : words)
    {
        bool flag = true;
        for (const auto& e : word)
            if (!vst[e])
            {
                flag = false;
                break;
            }
        if (flag)
            ++cnt;
    }
    return cnt;
}

void solve(int cnt = 0, int idx = 'a')
{
    if (cnt == k)
    {
        res = max(res, count());
        return;
    }
    for (int i = idx; i <= 'z'; ++i)
    {
        if (vst[i])
            continue;
        vst[i] = true;
        solve(cnt + 1, i);
        vst[i] = false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    k -= 5;
    words.reserve(n);
    while (n--)
    {
        cin >> input;
        words.push_back(input);
    }
    for (const auto& e : exist)
        vst[e] = true;
    solve();
    cout << res;
    return 0;
}