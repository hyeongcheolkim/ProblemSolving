//baekjoon ps 2688

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
ull cache[70][70];

ull number_of_digits(int number, int last_value)
{
    ull &ret = cache[number][last_value];
    if (number == 1)
        return 1;
    if (ret != 0)
        return ret;
    for (int idx = last_value; idx <= 9; ++idx)
        ret += number_of_digits(number - 1, idx);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << number_of_digits(n + 1, 0) << '\n';
    }
    return 0;
}