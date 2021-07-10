//baekjoon ps 13549

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    deque<pair<int, int>> q;
    vector<int> check(200000 + 1, numeric_limits<int>::max());
    q.push_front({n, 0});
    check[n] = 0;
    while (!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second;
        if (pos == k)
            break;
        q.pop_front();
        if (pos + 1 <= 100000 && cnt < check[pos + 1])
        {
            check[pos + 1] = cnt + 1;
            q.push_back({pos + 1, cnt + 1});
        }
        if (pos - 1 >= 0 && cnt < check[pos - 1])
        {
            check[pos - 1] = cnt + 1;
            q.push_back({pos - 1, cnt + 1});
        }
        if (pos * 2 <= 200000 && cnt < check[pos * 2])
        {
            check[pos * 2] = cnt;
            q.push_front({pos * 2, cnt});
        }
    }
    cout << q.front().second;
    return 0;
}