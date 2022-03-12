#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n, n != 0)
    {
        long long max_area = 0;
        stack<long long> remain_idx;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i)
            cin >> heights[i];
        heights.push_back(0);
        for (int i = 0; i < n + 1; ++i)
        {
            while (!remain_idx.empty() && heights[remain_idx.top()] >= heights[i])
            {
                long long height = heights[remain_idx.top()];
                remain_idx.pop();
                long long width = -1;
                if (!remain_idx.empty())
                    width = i - remain_idx.top() - 1;
                else
                    width = i;
                long long area = width * height;
                max_area = max(max_area, area);
            }
            remain_idx.push(i);
        }
        cout << max_area << '\n';
    }
    return 0;
}