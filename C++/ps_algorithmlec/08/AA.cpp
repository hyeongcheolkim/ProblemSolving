// cpp algorithm ps number 8

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int n = 0;
    int flag = 1;
    
    for (const auto &e:str)
    {
        if(e=='(')
            n++;
        if(e==')')
        {
            if(n<=0)
            {
                flag = 0;
                break;
            }
            n--;
        }     
    }

    if(flag==1)
        cout << "YES";
    if(flag==0)
        cout << "NO";

    return 0;
}