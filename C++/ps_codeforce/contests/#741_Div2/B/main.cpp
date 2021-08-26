#include <bits/stdc++.h>
using namespace std;

constexpr int mxK = 5e2, mxN = 1e7;
int len, arr[mxK + 1];
bool cache[mxN + 1], flag;

void dfs(int idx, int length, int size, int num)
{
    if (!cache[num] && flag)
    {
        cout << to_string(num).size() << '\n';
        cout << num << '\n';
        flag = false;
        return;
    }
    if (!flag || size == length || idx == len + 1)
        return;
    dfs(idx + 1, length, size + 1, num * 10 + arr[idx]);
    dfs(idx + 1, length, size, num);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 2; i <= mxN; ++i)
        cache[i] = true;
    cache[0] = true;
    for (int i = 1; i * i <= mxN; ++i)
        if (cache[i])
            for (int idx = i * i; idx <= mxN; idx += i)
                cache[idx] = false;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> len;
        for (int i = 1; i <= len; ++i)
        {
            char temp;
            cin >> temp;
            arr[i] = temp - '0';
        }
        for (int i = 1; i <= len; ++i)
        {
            flag = true;
            dfs(1, i, 0, 0);
            if (!flag)
                break;
        }
    }
    return 0;
}