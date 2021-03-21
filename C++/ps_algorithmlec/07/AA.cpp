// cpp algorithm ps number 7

#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin,str);

    for(auto &e:str)
        e = tolower(e);
    for(auto &e:str)
        if(e!=' ')
            cout << e;
    
    return 0;
}