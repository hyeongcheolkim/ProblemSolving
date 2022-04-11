#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 26;
int n;
long double val[mxN];
string statement;
stack<long double> s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> statement;
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    for (const auto& e : statement)
    {
        if ('A' <= e && e <= 'Z')
        {
            s.push(val[e - 'A']);
            continue;
        }
        long double second = s.top();
        s.pop();
        long double first = s.top();
        s.pop();
        switch (e)
        {
            case '+':
                s.push(first + second);
                break;
            case '-':
                s.push(first - second);
                break;
            case '*':
                s.push(first * second);
                break;
            case '/':
                s.push(first / second);
                break;
            default:
                break;
        }
    }
    cout << setprecision(2) << fixed << s.top();
    return 0;
}