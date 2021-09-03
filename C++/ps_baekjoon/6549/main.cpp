#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n, n != 0)
    {
        ull res = 0;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
            cin >> heights[i];
        stack<int> s;
        for (int now_idx = 0; now_idx < n; now_idx++)
        {
            while (!s.empty() && heights[s.top()] >= heights[now_idx])
            {
                int height = heights[s.top()];
                s.pop();
                ull width = s.empty() ? now_idx : now_idx - s.top() - 1;
                res = max(res, height * width);
            }
            s.push(now_idx);
        }
        while (!s.empty())
        {
            int height = heights[s.top()];
            s.pop();
            ull width = s.empty() ? n : n - s.top() - 1;
            res = max(res, height * width);
        }
        cout << res << '\n';
    }
    return 0;
}