#include <bits/stdc++.h>
using namespace std;

char buff;
int q, prev_idx;
vector<unordered_map<char, int>> cnt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cnt.resize(1);
    while ((buff = cin.get()) != '\n')
    {
        unordered_map<char, int> tmp;
        for (char c = 'a'; c <= 'z'; ++c)
            tmp[c] += cnt[prev_idx][c] + (c == buff);
        cnt.push_back(tmp);
        ++prev_idx;
    }
    cin >> q;
    while (q--)
    {
        char c;
        int from, to;
        cin >> c >> from >> to;
        cout << cnt[++to][c] - cnt[from][c] << '\n';
    }
    return 0;
}