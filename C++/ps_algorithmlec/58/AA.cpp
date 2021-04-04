// cpp algorithm ps number 58

#include <iostream>

using namespace std;

void fnc(int n)
{
    if(n>7)
        return;
    fnc(n * 2);
    fnc(n * 2 + 1);
    cout << n;
}

int main()
{
    int n;
    cin >> n;
    fnc(n);

    return 0;
}