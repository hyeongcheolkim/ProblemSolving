// cpp algorithm ps number 54

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int open=0;
    int close = 0;
    bool flag = true;
    char a;
    while((a=getchar())!='\n')
    {
        if(a=='(')
            open++;
        if(a==')')
            close++;
        if(close>open)
        {
            flag = false;
            break;
        }
    }
    if(open!=close)
        flag = false;

    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}