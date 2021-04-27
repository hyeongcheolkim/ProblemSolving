//baekjoon ps 4949

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int t;
    char a;
    stack<char> s;
    string str;
    while (true)
    {
        static bool flag;
        flag = true;
        getline(cin, str);
        if(str==".")
            break;
        for (int i = 0; i < str.length(); i++)
            switch (str[i])
            {
            case '(':
                s.push(str[i]);
                break;
            case '[':
                s.push(str[i]);
                break;
            case ')':
                if (s.empty())
                    flag = false;
                else if(s.top()=='(')
                    s.pop();
                else if(s.top()=='[')
                    flag = false;
                break;
            case ']':
                if (s.empty())
                    flag = false;
                else if(s.top()=='[')
                    s.pop();
                else if(s.top()=='(')
                    flag = false;
                break;
            }
        if(!s.empty())
            flag = false;
        cout << (flag ? "yes" : "no") << '\n';
        while(!s.empty())
            s.pop();
    }
    return 0;
}