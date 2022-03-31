#include <bits/stdc++.h>
using namespace std;

stack<char> s;
char buff;
bool flag = false;
int res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while ((buff = cin.get()) != '\n')
    {
        if (buff == '(')
            flag = true;
        if (s.empty())
        {
            s.push(buff);
            continue;
        }
        if (s.top() == '(' && buff == ')')
            if (flag)
            {
                s.pop();
                res += s.size();
                flag = false;
                continue;
            }
            else
            {
                s.pop();
                res += 1;
                continue;
            }
        s.push(buff);
    }
    cout << res;
    return 0;
}