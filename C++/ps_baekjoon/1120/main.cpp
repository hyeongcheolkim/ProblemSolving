#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int mini = INF;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i <= b.size() - a.size(); ++i)
    {
        int cnt = 0;
        string sub_b = b.substr(i, a.size());
        for (int i = 0; i < a.size(); ++i)
            if (sub_b[i] != a[i])
                ++cnt;
        mini = min(mini, cnt);
    }
    cout << mini;
    return 0;
}