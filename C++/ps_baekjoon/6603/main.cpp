#include <bits/stdc++.h>
using namespace std;

int k;

void dfs_print(int idx, const vector<int>& num)
{
    static vector<int> tmp;
    if (tmp.size() == 6)
    {
        for (const auto& e : tmp)
            cout << e << ' ';
        cout << '\n';
        return;
    }
    for (int i = idx + 1; i < num.size(); ++i)
    {
        tmp.push_back(num[i]);
        dfs_print(i, num);
        tmp.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> k, k != 0)
    {
        vector<int> num(k);
        for (int i = 0; i < k; ++i)
            cin >> num[i];
        dfs_print(-1, num);
        cout << '\n';
    }
    return 0;
}