#include <bits/stdc++.h>
using namespace std;

int n, m;
struct candidate;
map<int, candidate> candidates;

struct candidate
{
    int recmd, time;
    bool operator<(const candidate& that) const
    {
        if (this->recmd == that.recmd)
            return this->time < that.time;
        else
            return this->recmd < that.recmd;
    }
};

void gc()
{
    auto mini = *min_element(candidates.begin(), candidates.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    candidates.erase(mini.first);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--)
    {
        static int time = 0;
        int num;
        cin >> num;
        if (candidates.contains(num))
            ++candidates[num].recmd;
        else
        {
            if (candidates.size() >= n)
                gc();
            ++candidates[num].recmd;
            candidates[num].time = ++time;
        }
    }
    for (const auto& e : candidates)
        cout << e.first << ' ';
    return 0;
}