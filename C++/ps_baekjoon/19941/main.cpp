#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
string str;
vector<bool> vst;

bool can_eat(int idx)
{
    const int len = str.size();
    for (int i = idx - k; i <= idx + k; ++i)
    {
        if (!(0 <= i && i < len))
            continue;
        if (vst[i])
        {
            vst[i] = false;
            return true;
        }
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> str;
    const int len = str.size();
    vst.resize(len);
    for (int i = 0; i < len; ++i)
        if (str[i] == 'H')
            vst[i] = true;
    for (int i = 0; i < len; ++i)
        if (str[i] == 'P' && can_eat(i))
            ++cnt;
    cout << cnt;
    return 0;
}