#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e6;
bool prime[5 * mxN + 1];

bool is_palindrome(const int& num)
{
    string str1 = to_string(num);
    string str2{str1};
    reverse(str2.begin(), str2.end());
    if (str1 == str2)
        return true;
    else
        return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    memset(&prime, true, sizeof(prime));
    prime[1] = false;
    for (int num = 2; num * num <= 5 * mxN; ++num)
        if (prime[num])
        {
            for (int i = num + num; i <= 5 * mxN; i += num)
                prime[i] = false;
        }
    for (int i = n; i <= 5 * mxN; ++i)
        if (prime[i] && is_palindrome(i))
        {
            cout << i;
            break;
        }
    return 0;
}