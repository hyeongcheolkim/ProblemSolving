#include <bits/stdc++.h>
using namespace std;

int init_num, maxi, maxi_len;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> init_num;
    for (int i = 1; i <= init_num; ++i)
    {
        int len = 2;
        int first = init_num;
        int second = i;
        while (first - second >= 0)
        {
            swap(first, second);
            second = second - first;
            ++len;
        }
        if (len > maxi_len)
        {
            maxi_len = len;
            maxi = i;
        }
    }
    cout << maxi_len << '\n';
    int first = init_num;
    int second = maxi;
    cout << first << ' ' << second << ' ';
    while (first - second >= 0)
    {
        swap(first, second);
        cout << (second = second - first) << ' ';
    }
    return 0;
}