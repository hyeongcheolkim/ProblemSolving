//baekjoon ps 9012

#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int t;
    char a;
    stack<char> s;
    cin >> t;
    while (getchar() != '\n')
        continue;
    while (t--)
    {
        static bool flag;
        flag = true;
        while ((a = getchar()) != '\n')
        {
            if (a == '(')
                s.push(a);
            if (a == ')')
            {
                if (s.empty())
                    flag = false;
                else
                    s.pop();
            }
        }
        if(!s.empty())
            flag = false;
        cout << (flag ? "YES" : "NO") << '\n';
        while(s.size()!=0)
            s.pop();
    }
    return 0;
}