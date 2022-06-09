#include <bits/stdc++.h>
using namespace std;

constexpr long long mxVal = 1e14;
long long a, b, cnt;
vector<bool> is_prime;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    long long len = sqrt(mxVal);
    is_prime.resize(len + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= len; ++i)
        if (is_prime[i])
            for (long long j = i + i; j <= len; j += i)
                is_prime[j] = false;
    for (long long base = 2; base <= sqrt(b); ++base)
        if (is_prime[base])
        {
            int low = max(2, (int)ceil(log(a) / log(base)));
            int up = max(2, (int)floor(log(b) / log(base)));
            cnt += up - low + 1;
        }
    cout << cnt;
    return 0;
}