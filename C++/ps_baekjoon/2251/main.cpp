#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 200;
int a, b, c;
queue<tuple<int, int, int>> q;
bool vst[mxN + 1][mxN + 1];
vector<int> res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    q.emplace(0, 0, c);
    vst[0][0] = true;
    while (!q.empty())
    {
        const auto [na, nb, nc] = q.front();
        q.pop();
        if (na == 0)
            res.push_back(nc);
        if (na + nb > b)
        {
            if (!vst[na + nb - b][b])
            {
                vst[na + nb - b][b] = true;
                q.emplace(na + nb - b, b, nc);
            }
        }
        else
        {
            if (!vst[0][na + nb])
            {
                vst[0][na + nb] = true;
                q.emplace(0, na + nb, nc);
            }
        }
        if (na + nc > c)
        {
            if (!vst[na + nb - c][nb])
            {
                vst[na + nb - c][nb] = true;
                q.emplace(na + nb - c, nb, c);
            }
        }
        else
        {
            if (!vst[0][nb])
            {
                vst[0][nb] = true;
                q.emplace(0, nb, na + nc);
            }
        }
        if (nb + na > a)
        {
            if (!vst[a][nb + na - a])
            {
                vst[a][nb + na - a] = true;
                q.emplace(a, nb + na - a, nc);
            }
        }
        else
        {
            if (!vst[na + nb][0])
            {
                vst[na + nb][0] = true;
                q.emplace(na + nb, 0, nc);
            }
        }
        if (nb + nc > c)
        {
            if (!vst[na][nb + nc - c])
            {
                vst[na][nb + nc - c] = true;
                q.emplace(na, nb + nc - c, c);
            }
        }
        else
        {
            if (!vst[na][0])
            {
                vst[na][0] = true;
                q.emplace(na, 0, nb + nc);
            }
        }
        if (nc + na > a)
        {
            if (!vst[a][nb])
            {
                vst[a][nb] = true;
                q.emplace(a, nb, nc + na - a);
            }
        }
        else
        {
            if (!vst[nc + na][nb])
            {
                vst[nc + na][nb] = true;
                q.emplace(nc + na, nb, 0);
            }
        }
        if (nc + nb > b)
        {
            if (!vst[na][b])
            {
                vst[na][b] = true;
                q.emplace(na, b, nc + nb - b);
            }
        }
        else
        {
            if (!vst[na][nb + nc])
            {
                vst[na][nb + nc] = true;
                q.emplace(na, nb + nc, 0);
            }
        }
    }
    sort(res.begin(), res.end());
    for (const auto& e : res)
        cout << e << ' ';
    return 0;
}