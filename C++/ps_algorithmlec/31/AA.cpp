// cpp algorithm ps number 31

#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int c=0;
    int h=0;

    for (int i = 0; i < str.size();i++)
    {
        if(str[i]=='C')
            for (i=i+1; i < str.size() && isdigit(str[i]);i++)
                c = c * 10 + (str[i] - '0');
        if(str[i]=='H')
            for (i=i+1; i < str.size() && isdigit(str[i]);i++)
                h = h * 10 + (str[i] - '0');
    }
    if(c==0)
        c = 1;
    if(h==0)
        h = 1;
    cout << c*12 + h*1;
    return 0;
}