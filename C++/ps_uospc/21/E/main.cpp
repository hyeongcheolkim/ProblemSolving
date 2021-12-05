#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 5;
int n, cnt1, cnt2;
char arr[mxN + 1], c;
stack<char> s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        char c = arr[i];
        if (s.empty())
            s.push(c);
        else
        {
            if (s.top() == '(' && c == ')')
                s.pop();
            else if (s.top() == '(' && c == '(')
                s.push('(');
            else if (s.top() == ')' && c == ')')
            {
                ++cnt2;
                s.pop();
            }
            else if (s.top() == ')' && c == '(')
            {
                cnt2 += 2;
                s.pop();
            }
        }
    }
    cout << cnt2;
    return 0;
}