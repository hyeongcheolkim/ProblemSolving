// cpp algorithm ps number 57

#include <iostream>

using namespace std;

void print(int n)
{
    if(n==0)
        return;
    print(n/2);
    cout << n % 2;
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}