#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
array<bool, 10000> is_prime;
array<int, 10000> vst;

void build_is_prime()
{
    fill(is_prime.begin(), is_prime.end(), true);
    for (int i = 2; i * i <= 9999; ++i)
        if (is_prime[i])
            for (int j = i + i; j <= 9999; j += i)
                is_prime[j] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    build_is_prime();
    int t;
    cin >> t;
    while (t--)
    {
        fill(vst.begin(), vst.end(), INF);
        int from, to;
        cin >> from >> to;
        queue<int> q;
        q.push(from);
        vst[from] = 0;
        while (!q.empty())
        {
            auto now = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                string str_now = to_string(now);
                for (char j = '0'; j <= '9'; ++j)
                {
                    str_now[i] = j;
                    int next = stoi(str_now);
                    if (next < 1000)
                        continue;
                    if (is_prime[next] && vst[next] > vst[now] + 1)
                    {
                        vst[next] = vst[now] + 1;
                        q.push(next);
                    }
                }
            }
        }
        if (vst[to] == INF)
            cout << "Impossible\n";
        else
            cout << vst[to] << '\n';
    }
    return 0;
}
