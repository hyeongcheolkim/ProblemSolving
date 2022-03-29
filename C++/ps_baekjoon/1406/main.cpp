#include <bits/stdc++.h>
using namespace std;

stack<char> lt, rt;
int m;
char tmp, oper;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while ((tmp = cin.get()) != '\n')
        lt.push(tmp);
    cin >> m;
    while (m--)
    {
        cin >> oper;
        switch (oper)
        {
            case 'L':
                if (lt.empty())
                    continue;
                rt.push(lt.top());
                lt.pop();
                break;
            case 'D':
                if (rt.empty())
                    continue;
                lt.push(rt.top());
                rt.pop();
                break;
            case 'B':
                if (lt.empty())
                    continue;
                lt.pop();
                break;
            case 'P':
                cin >> tmp;
                lt.push(tmp);
                break;
            default:
                break;
        }
    }
    while (!lt.empty())
    {
        rt.push(lt.top());
        lt.pop();
    }
    while (!rt.empty())
    {
        cout << rt.top();
        rt.pop();
    }
    return 0;
}