#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull mini, maxi;
vector<bool> is_target;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> mini >> maxi;
    is_target.resize(maxi - mini + 1, true);
    for (ull i = 2; i * i <= maxi; ++i)
    {
        ull pow_val = i * i;
        ull start;
        if (mini / pow_val * pow_val == mini)
            start = (mini / pow_val) * pow_val;
        else
            start = (mini / pow_val + 1) * pow_val;
        for (ull j = start; j <= maxi; j += pow_val)
            is_target[j - mini] = false;
    }
    cout << count(is_target.begin(), is_target.end(), true);
    return 0;
}