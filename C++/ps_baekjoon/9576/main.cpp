#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, cnt = 0;
        cin >> n >> m;
        vector<pair<int, int>> arr;
        vector<bool> vst(n + 1);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            arr.emplace_back(a, b);
        }
        sort(arr.begin(), arr.end(), [](const pair<int, int>& e1, const pair<int, int>& e2) {
            const auto& [a1, b1] = e1;
            const auto& [a2, b2] = e2;
            if (b1 == b2)
                return a2 < a1;
            else
                return b1 < b2;
        });
        for (const auto& [a, b] : arr)
            for (int i = a; i <= b; ++i)
                if (!vst[i])
                {
                    vst[i] = true;
                    ++cnt;
                    break;
                }
        cout << cnt << '\n';
    }
    return 0;
}