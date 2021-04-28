//baekjoon ps 1966

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        static int n, m;
        static int cnt;
        static queue<pair<int, int>> q;
        static priority_queue<pair<int, int>> pq;
        cnt = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            static int input;
            cin >> input;
            q.push({input, i});
            pq.push({input, i});
        }
        while (!q.empty())
        {
            if (pq.top().first == q.front().first)
                if (q.front().second == m)
                {
                    cnt++;
                    cout << cnt << '\n';
                    break;
                }
                else
                {
                    cnt++;
                    pq.pop();
                    q.pop();
                }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();
    }
    return 0;
}