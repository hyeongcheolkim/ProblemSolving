// cpp algorithm ps number 55

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> mid;
    stack<int> city;
    string str = "";
    mid.push(0);
    city.push(0);

    while (n--)
    {
        static int in;
        cin >> in;
        mid.push(in);
        str += "P";

        while (city.top() + 1 == mid.top())
        {
            str += "O";
            city.push(mid.top());
            mid.pop();
        }
    }
    if (mid.size() == 1)
        cout << str;
    else
        cout << "impossible";
    return 0;
}