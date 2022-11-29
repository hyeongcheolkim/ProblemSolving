#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 5;
int n, res;
vector<array<int, SIZE>> card;

void solve(array<int, SIZE> arr, int idx, int& ret)
{
    static vector<int> mem;
    if (mem.size() == 3)
    {
        auto sum = reduce(mem.begin(), mem.end(), 0, plus<int>());
        ret = max(ret, to_string(sum).back() - '0');
        return;
    }
    for (int i = idx; i < SIZE; ++i)
    {
        mem.push_back(arr[i]);
        solve(arr, i + 1, ret);
        mem.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    card.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < SIZE; ++j)
            cin >> card[i][j];
    for (int i = 1; i <= n; ++i)
    {
        static int maxi = -1;
        int ret = -1;
        solve(card[i], 0, ret);
        if (ret >= maxi)
        {
            maxi = ret;
            res = i;
        }
    }
    cout << res;
    return 0;
}