// cpp algorithm ps number 6

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string input;
    string str;
    getline(cin,input);
    vector<char> arr;

    for (const auto &e:input)
        if(isdigit(e))
            arr.push_back(e);

    int flag = 0;
    for (const auto &e:arr)
    {
        if(e!='0')
            flag = 1;
        if(flag)
            str +=e;
    }

    int n = 0;
    stringstream temp(str);
    temp >> n;

    int total = 0;
    cout << n << "\n";
    for (int i = 1; i <= n;i++)
        if(n%i==0)
            total++;
    cout << total;

    return 0;
}