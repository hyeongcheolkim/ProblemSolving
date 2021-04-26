//baekjoon ps 1541

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    int input = 0;
    int minus = 0;
    int plus = 0;
    cin >> str;
    str += '+';
    for (int i = 0; i < str.length(); i++)
        if ('0' <= str[i] && str[i] <= '9')
            input = input * 10 + str[i] - '0';
        else if (str[i] == '+')
        {
            plus += input;
            input = 0;
        }
        else if (str[i] == '-')
        {
            plus += input;
            input = 0;
            for (i = i + 1; i < str.length(); i++)
                if ('0' <= str[i] && str[i] <= '9')
                    input = input * 10 + str[i] - '0';
                else if (str[i] == '+' || str[i] == '-')
                {
                    minus -= input;
                    input = 0;
                }
        }
    cout << minus + plus;
    return 0;
}