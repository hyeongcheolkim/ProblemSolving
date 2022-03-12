#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> heights;

long long solveStack()
{
    stack<long long> remaining;
    heights.push_back(0);
    long long ret = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        while (!remaining.empty() && heights[remaining.top()] >= heights[i])
        {
            long long j = remaining.top();
            remaining.pop();
            long long width = -1;
            if (remaining.empty())
                width = i;
            else
                width = (i - remaining.top() - 1);
            ret = max(ret, heights[j] * width);
        }
        remaining.push(i);
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    heights.reserve(n);
    while (n--)
    {
        int height;
        cin >> height;
        heights.push_back(height);
    }
    cout << solveStack();
    return 0;
}