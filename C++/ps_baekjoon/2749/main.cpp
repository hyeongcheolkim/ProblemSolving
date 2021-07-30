//baekjoon ps 2749

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr unsigned int divider = 1'000'000;
    constexpr unsigned int period = 1'500'000;
    unsigned long long n;
    cin >> n;
    auto fibonacci = new unsigned int[period];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < period; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % divider;
    cout << fibonacci[n % period];
    delete[] fibonacci;
    return 0;
}