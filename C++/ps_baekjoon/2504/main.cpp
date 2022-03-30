#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> s;
int tmp = 1, res;

int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        switch (str[i])
        {
            case '(':
                tmp *= 2;
                s.push(str[i]);
                break;
            case '[':
                tmp *= 3;
                s.push(str[i]);
                break;
            case ')':
                if (s.empty() || s.top() != '(')
                {
                    cout << 0;
                    exit(0);
                }
                if (str[i - 1] == '(')
                    res += tmp;
                s.pop();
                tmp /= 2;
                break;
            case ']':
                if (s.empty() || s.top() != '[')
                {
                    cout << 0;
                    exit(0);
                }
                if (str[i - 1] == '[')
                    res += tmp;
                s.pop();
                tmp /= 3;
                break;
            default:
                break;
        }
    cout << (s.empty() ? res : 0);
    return 0;
}