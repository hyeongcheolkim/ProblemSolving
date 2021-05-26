//baekjoon ps 1918

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string str, res;
    cin >> str;
    stack<char> oper;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if ('A' <= c && c <= 'Z')
            res += c;
        else
        {
            switch (c)
            {
            case '*':
            case '/':
                while (!oper.empty() && (oper.top() == '*' || oper.top() == '/'))
                {
                    res += oper.top();
                    oper.pop();
                }
                oper.push(c);
                break;
            case '+':
            case '-':
                while (!oper.empty() && oper.top() != '(')
                {
                    res += oper.top();
                    oper.pop();
                }
                oper.push(c);
                break;
            case '(':
                oper.push(c);
                break;
            case ')':
                while (!oper.empty() && oper.top() != '(')
                {
                    res += oper.top();
                    oper.pop();
                }
                oper.pop();
                break;
            default:
                break;
            }
        }
    }
    while (!oper.empty())
    {
        res += oper.top();
        oper.pop();
    }
    cout << res;
    return 0;
}