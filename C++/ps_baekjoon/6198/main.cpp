//baekjoon ps 6198

#include <iostream>
#include <utility>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long res = 0;
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    for (int index = 1; index <= n; index++)
    {
        int value;
        cin >> value;
        while (!s.empty() && s.top().second <= value)
        {
            res += index - s.top().first - 1;
            s.pop();
        }
        s.push({index, value});
    }
    int last_index = s.top().first;
    while (!s.empty())
    {
        res += last_index - s.top().first;
        s.pop();
    }
    cout << res;
    return 0;
}