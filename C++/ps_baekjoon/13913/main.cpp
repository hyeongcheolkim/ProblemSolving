//baekjoon ps 13913

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int SIZE = 100000;
    constexpr int INF = numeric_limits<int>::max();
    int n, k;
    cin >> n >> k;
    vector<int> check(2 * SIZE + 1, INF);
    vector<int> trace(2 * SIZE + 1, -1);
    vector<int> res;
    queue<pair<int, int>> q;
    q.push({n, 0});
    check[n] = 0;
    trace[n] = n;
    while (!q.empty())
    {
        int nowpos = q.front().first;
        int nowcnt = q.front().second;
        if (nowpos == k)
            break;
        q.pop();
        if (nowpos - 1 >= 0 && check[nowpos - 1] > nowcnt + 1)
        {
            q.push({nowpos - 1, nowcnt + 1});
            check[nowpos - 1] = nowcnt + 1;
            trace[nowpos - 1] = nowpos;
        }
        if (nowpos + 1 <= SIZE && check[nowpos + 1] > nowcnt + 1)
        {
            q.push({nowpos + 1, nowcnt + 1});
            check[nowpos + 1] = nowcnt + 1;
            trace[nowpos + 1] = nowpos;
        }
        if (nowpos * 2 <= SIZE * 2 && check[nowpos * 2] > nowcnt + 1)
        {
            q.push({nowpos * 2, nowcnt + 1});
            check[nowpos * 2] = nowcnt + 1;
            trace[nowpos * 2] = nowpos;
        }
    }
    int pos = q.front().first;
    int cnt = q.front().second;
    res.reserve(cnt + 1);
    while (true)
    {
        res.push_back(pos);
        if (trace[pos] == pos)
            break;
        pos = trace[pos];
    }
    reverse(res.begin(), res.end());
    cout << cnt << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}