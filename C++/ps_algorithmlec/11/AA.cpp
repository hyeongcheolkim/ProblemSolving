// cpp algorithm ps number 11

#include <iostream>

using namespace std;

int main()
{
    int n;
    int total = 0;
    cin >> n;

    if(n>=100'000)
        total = 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000;
    else if(n>=10'000)
        total = 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * (n-9999);
    else if(n>=1'000)
        total = 9 + 2 * 90 + 3 * 900 + 4 * (n-999);
    else if(n>=100)
        total = 9 + 2 * 90 + 3 * (n - 99);
    else if(n>=10)
        total = 9 + 2 * (n-9);
    else
        total = 9 * n;

    cout << total;

    return 0;
}