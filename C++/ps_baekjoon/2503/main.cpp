#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<tuple<int, int, int>> score;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    score.reserve(n);
    while (n--)
    {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        score.emplace_back(num, strike, ball);
    }
    for (int i = 100; i <= 999; ++i)
    {
        string i_str = to_string(i);
        if (count(i_str.begin(), i_str.end(), '0') != 0)
            continue;
        if (i_str[0] == i_str[1] || i_str[1] == i_str[2] || i_str[0] == i_str[2])
            continue;
        for (const auto& [num, strike, ball] : score)
        {
            int strike_cnt = 0, ball_cnt = 0;
            string num_str = to_string(num);
            for (int i = 0; i < 3; ++i)
                if (i_str[i] == num_str[i])
                    ++strike_cnt;
                else
                    for (int j = 0; j < 3; ++j)
                    {
                        if (i == j)
                            continue;
                        if (i_str[i] == num_str[j])
                            ++ball_cnt;
                    }
            if (ball != ball_cnt || strike != strike_cnt)
                goto break_loop;
        }
        ++cnt;
    break_loop:
        continue;
    }
    cout << cnt;
    return 0;
}