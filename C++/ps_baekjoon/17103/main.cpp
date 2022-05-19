#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e6;
array<bool, mxN + 1> is_prime;

void init_is_prime_arr()
{
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= mxN; ++i)
        if (is_prime[i])
            for (int j = i + i; j <= mxN; j += i)
                is_prime[j] = false;
}

int solve(int num)
{
    int ret = 0;
    int lt = 2;
    int rt = num - 1;
    const auto move_ptr = [&]
    {
        while (!is_prime[lt])
            ++lt;
        while (!is_prime[rt])
            --rt;
    };
    while (move_ptr(), lt <= rt)
    {
        if (lt + rt == num)
        {
            ++ret;
            ++lt;
        }
        else if (lt + rt < num)
            ++lt;
        else if (lt + rt > num)
            --rt;
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    init_is_prime_arr();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}