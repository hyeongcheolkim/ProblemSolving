#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e6;
int n, k, maxi;
bool vst[mxN + 1];
queue<int> q, tq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    q.push(n);
    while (k--)
    {
        while (!q.empty())
        {
            auto now_int = q.front();
            auto now_str = to_string(now_int);
            q.pop();
            auto len = now_str.length();
            for (int i = 0; i < len - 1; ++i)
                for (int j = i + 1; j < len; ++j)
                {
                    auto next_str = now_str;
                    swap(next_str[i], next_str[j]);
                    if (next_str[0] == '0')
                        continue;
                    auto next_int = stoi(next_str);
                    if (vst[next_int])
                        continue;
                    vst[next_int] = true;
                    tq.push(next_int);
                }
        }
        q.swap(tq);
        memset(vst, false, sizeof(vst));
    }
    while (!q.empty())
    {
        maxi = max(maxi, q.front());
        q.pop();
    }
    cout << (maxi == 0 ? -1 : maxi);
    return 0;
}