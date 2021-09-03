#include <bits/stdc++.h>
using namespace std;

int n;

bool is_prime(const int &num)
{
    if (num == 0 || num == 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;
    return true;
}

void dfs(int num, int len = 1)
{
    if (len == n)
    {
        cout << num << '\n';
        return;
    }
    for (int i = 1; i <= 9; i += 2)
    {
        if (is_prime(num * 10 + i))
            dfs(num * 10 + i, len + 1);
    }
}

int main()
{
    cin >> n;
    for (const auto &e : {2, 3, 5, 7})
        dfs(e);
    return 0;
}