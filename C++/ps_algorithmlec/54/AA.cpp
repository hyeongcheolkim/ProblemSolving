// cpp algorithm ps number 54

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> arr;
    char a;
    while ((a = getchar()) != '\n')
    {
        if (a == '(')
            arr.push(a);
        else if (a == ')')
        {
            if (arr.empty())
            {
                cout << "NO";
                return 0;
            }
            else
                arr.pop();
        }
    }
    if (arr.empty())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}