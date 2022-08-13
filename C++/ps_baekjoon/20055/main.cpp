#include <bits/stdc++.h>
using namespace std;

int n, k, step;
struct Area
{
    int dur = 0;
    bool exist = false;
};
deque<Area> top, bot;

void init()
{
    cin >> n >> k;
    top.resize(n);
    bot.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> top[i].dur;
    for (int i = n - 1; i >= 0; --i)
        cin >> bot[i].dur;
}

void pop_robot()
{
    top.back().exist = false;
}

void rotate_belt()
{
    top.push_front(bot.front());
    bot.push_back(top.back());
    top.pop_back();
    bot.pop_front();
    pop_robot();
}

void test_and_move()
{
    for (int i = n - 2; i >= 0; --i)
        if (top[i].exist && !top[i + 1].exist && top[i + 1].dur >= 1)
        {
            top[i].exist = false;
            top[i + 1].exist = true;
            --top[i + 1].dur;
        }
    pop_robot();
}

void push_robot()
{
    if (!top.front().exist && top.front().dur >= 1)
    {
        top.front().exist = true;
        --top.front().dur;
    }
}

int count_zero_dur()
{
    int top_cnt = count_if(top.begin(), top.end(), [](const Area& e) {
        return e.dur == 0;
    });
    int bot_cnt = count_if(bot.begin(), bot.end(), [](const Area& e) {
        return e.dur == 0;
    });
    return top_cnt + bot_cnt;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    init();
    do
    {
        rotate_belt();
        test_and_move();
        push_robot();
    } while (++step, count_zero_dur() < k);
    cout << step;
    return 0;
}