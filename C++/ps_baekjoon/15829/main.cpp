//baekjoon ps 15829

#include <iostream>
#include <algorithm>

using namespace std;

constexpr unsigned int implier = 31;
constexpr unsigned long long mode = 1234567891;

unsigned long long power(unsigned long long num, int n)
{
    unsigned long long temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp *= num;
        temp %= mode;
    }
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int l;
    cin >> l;
    unsigned long long res = 0;
    for (int i = 0; i < l; i++)
    {
        static char input;
        cin >> input;
        res += (input - 'a' + 1) * power(implier, i);
        res %= mode;
    }
    cout << res;
    return 0;
}