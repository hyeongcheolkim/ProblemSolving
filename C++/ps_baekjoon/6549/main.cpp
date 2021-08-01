//baekjoon ps 6549

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n, n != 0)
    {
        unsigned long long res = 0;
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
                unsigned long long width = s.empty() ? now_idx : now_idx - s.top() - 1;
                res = max(res, height * width);
            }
            s.push(now_idx);
        }
        while (!s.empty())
        {
            int height = heights[s.top()];
            s.pop();
            unsigned long long width = s.empty() ? n : n - s.top() - 1;
            res = max(res, height * width);
        }
        cout << res << '\n';
    }
    return 0;
}