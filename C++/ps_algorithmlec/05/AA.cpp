// cpp algorithm ps number 5

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    char* str_age;
    getline(cin, str);

    int a = str[0] - '0';
    int b = str[1] - '0';

    if(str[7]=='1'||str[7]=='2')
        cout << 100 - (a * 10 + b) + 20;

    if(str[7]=='3'||str[7]=='4')
        cout << 20 - (a * 10 + b) ;    

    if(str[7]=='1')
        cout << "M";
    else if (str[7]=='2')
        cout << "W";
    if(str[7]=='3')
        cout << "M";
    else if (str[7]=='4')
        cout << "W";

    return 0;
}