// ps number 1

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        if(i%m==0)
            sum += i;
    cout << sum;
    return 0;
}