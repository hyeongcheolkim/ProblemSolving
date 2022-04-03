#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<bool> number(n + 1, true);
    for (int i = 2; i <= n; ++i)
        if (number[i])
            for (int j = i; j <= n; j += i)
                if (number[j])
                {
                    number[j] = false;
                    ++cnt;
                    if (cnt == k)
                    {
                        cout << j;
                        exit(0);
                    }
                }
    return 0;
}