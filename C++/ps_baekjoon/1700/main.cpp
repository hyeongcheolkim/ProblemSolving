#include <bits/stdc++.h>
using namespace std;

class Scheduler
{
private:
    const vector<int>& order;
    vector<bool> run_q;
    unordered_set<int> run_q_s;
    int run_q_size;

    void pop_task(int idx)
    {
        auto tmp_run_q_s = run_q_s;
        for (int i = idx + 1; i < order.size() && tmp_run_q_s.size() > 1; ++i)
            tmp_run_q_s.erase(order[i]);
        int pop_target = *tmp_run_q_s.begin();
        run_q_s.erase(pop_target);
        run_q[pop_target] = false;
    }
public:
    Scheduler(const vector<int>& order, const int& run_q_size, const int& kind) : order{order}
    {
        this->run_q_size = run_q_size;
        run_q.resize(kind + 1);
    }

    bool push_task(int idx)
    {
        int task = order[idx];
        bool ret = false;
        if (run_q[task])
            return ret;
        if (run_q_s.size() >= run_q_size)
        {
            pop_task(idx);
            ret = true;
        }
        run_q_s.insert(task);
        run_q[task] = true;
        return ret;
    }
};

int n, k, cnt;
vector<int> order;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    order.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> order[i];
    Scheduler scheduler{order, n, k};
    for (int i = 0; i < k; ++i)
        if (scheduler.push_task(i))
            ++cnt;
    cout << cnt;
    return 0;
}