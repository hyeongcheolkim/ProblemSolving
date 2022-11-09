#include <bits/stdc++.h>
using namespace std;

int n, maxi;
vector<vector<int>> hit;
vector<int> order{1, 2, 3, 4, 5, 6, 7, 8};

int move_base(vector<bool>& base, const int& diff)
{
    int ret = 0;
    for (int i = 3; i >= 1; --i)
        if (base[i])
        {
            base[i] = false;
            if (i + diff > 3)
            {
                ++ret;
                continue;
            }
            base[i + diff] = true;
        }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    hit.resize(n, vector<int>(9));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> hit[i][j];
    do
    {
        deque<int> dq{order.begin(), order.end()};
        dq.insert(dq.begin() + 3, 0);
        int score = 0;
        for (int inning = 0; inning < n; ++inning)
        {
            int out_cnt = 0;
            vector<bool> base(3 + 1, false);
            while (out_cnt != 3)
            {
                auto hitter = dq.front();
                dq.pop_front();
                dq.push_back(hitter);
                switch (hit[inning][hitter])
                {
                    case 0:
                        ++out_cnt;
                        break;
                    case 1:
                        score += move_base(base, 1);
                        base[1] = true;
                        break;
                    case 2:
                        score += move_base(base, 2);
                        base[2] = true;
                        break;
                    case 3:
                        score += move_base(base, 3);
                        base[3] = true;
                        break;
                    case 4:
                        score += move_base(base, 4);
                        score += 1;
                        break;
                }
            }
        }
        maxi = max(maxi, score);
    } while (next_permutation(order.begin(), order.end()));
    cout << maxi;
    return 0;
}