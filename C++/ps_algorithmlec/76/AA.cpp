// cpp algorithm ps number 76

#include <iostream>

using namespace std;

int fnc(int n, const int&r)
{
    static int index = 0;
    index++;
    if(r==index)
        return n;
    return n * fnc(n - 1,r);
}

int factorial(int n)
{
    if(n==1||n==0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n, r;
    cin >> n >> r;
    r = (r <= n - r) ? (r) : (n - r);
    cout << (fnc(n,r)/factorial(r));
    return 0;
}