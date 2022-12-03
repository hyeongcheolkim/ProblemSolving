#include <bits/stdc++.h>
using namespace std;

int n, sum, maxi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        maxi = max(maxi, num);
        sum += num;
    }
    if (sum % maxi == 0)
        cout << sum;
    else
        cout << (sum / maxi + 1) * (maxi);
        return 0;
}