#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> dq;
vector<int> num;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    num.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        dq.push_back(i);
    }
    while (!dq.empty())
    {
        int idx = dq.front();
        dq.pop_front();
        cout << idx << ' ';
        int move_num = num[idx];
        if (move_num >= 0)
        {
            while (--move_num)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            while (move_num++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}