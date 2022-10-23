#include <bits/stdc++.h>
using namespace std;

constexpr long long MAX_VAL = 1000000000;
int n, m;
long long res = 1;
vector<long long> arr1, arr2;
bool is_overflow = false;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr1.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];
    cin >> m;
    arr2.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> arr2[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            auto _gcd = gcd(arr1[i], arr2[j]);
            res *= _gcd;
            arr1[i] /= _gcd;
            arr2[j] /= _gcd;
            if (res >= MAX_VAL)
            {
                res %= MAX_VAL;
                is_overflow = true;
            }
        }
    if (is_overflow)
    {
        cout.width(9);
        cout.fill('0');
        cout << res;
    }
    else
        cout << res;
    return 0;
}