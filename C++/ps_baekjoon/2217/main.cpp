#include <bits/stdc++.h>
using namespace std;

int n, res;
vector<int> ropes;
stack<int> remaining;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    ropes.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> ropes[i];
    sort(ropes.begin(), ropes.end());
    ropes.push_back(0);
    for (int i = 0; i < ropes.size(); ++i)
    {
        while (!remaining.empty() && ropes[remaining.top()] >= ropes[i])
        {
            int j = remaining.top();
            remaining.pop();
            int width = -1;
            if (remaining.empty())
                width = i;
            else
                width = (i - remaining.top() - 1);
            res = max(res, ropes[j] * width);
        }
        remaining.push(i);
    }
    cout << res;
    return 0;
}