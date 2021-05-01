//baekjoon ps 11050

#include <iostream>

using namespace std;

int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n;i++)
        res *= i;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << factorial(n) / factorial(k) / factorial(n - k);
    return 0;
}