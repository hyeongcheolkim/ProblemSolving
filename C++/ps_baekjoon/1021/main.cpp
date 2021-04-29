//baekjoon ps 1021

#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    int size = n;
    queue<int> q;
    deque<int> dq(n);
    vector<bool> check(n + 1, false);
    for (int i = 0; i < n; i++)
        dq[i] = i + 1;
    for (int i = 0; i < m; i++)
    {
        static int index;
        cin >> index;
        q.push(index);
    }
    while (!q.empty())
    {
        if (q.front() == dq.front())
        {
            check[q.front()] = true;
            q.pop();
            dq.pop_front();
            size--;
        }
        else
        {
            static int front;
            front = 0;
            if (dq.front() > q.front())
            {
                for (int i = n; i >= dq.front(); i--)
                    if (!check[i])
                        front++;
                for (int i = 1; i <= q.front(); i++)
                    if (!check[i])
                        front++;
            }
            else
            {
                for (int i = dq.front(); i <= q.front();i++)
                    if(!check[i])
                        front++;
            }

            if (2 * front > size + 1)
                while (q.front() != dq.front())
                {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    cnt++;
                }
            else
                while (q.front() != dq.front())
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    cnt++;
                }
        }
    }
    cout << cnt;
    return 0;
}