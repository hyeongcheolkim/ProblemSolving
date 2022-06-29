#include <bits/stdc++.h>
using namespace std;

int n, m, t;
class Disk;
vector<Disk> disks;

class Disk
{
private:
    vector<int> data;
public:
    Disk() {}
    Disk(vector<int>& data) { this->data = move(data); }

    void rotate_counter_clock() { rotate(data.begin(), data.begin() + 1, data.end()); }

    void rotate_clock() { rotate(data.begin(), data.end() - 1, data.end()); }

    int& operator[] (int idx) { return data[idx]; }

    int sum() { return reduce(data.begin(), data.end(), 0, plus<int>()); }

    int valid_data_ea() { return count_if(data.begin(), data.end(), [](auto e) {return e > 0; }); }
};

vector<pair<int, int>> get_remove_target()
{
    vector<pair<int, int>> remove_target;
    for (int disk_num = 1; disk_num <= n; ++disk_num)
    {
        for (int idx = 0; idx < m - 1; ++idx)
            if (disks[disk_num][idx] && disks[disk_num][idx] == disks[disk_num][idx + 1])
            {
                remove_target.push_back({disk_num, idx});
                remove_target.push_back({disk_num, idx + 1});
            }
        if (disks[disk_num][0] && disks[disk_num][0] == disks[disk_num][m - 1])
        {
            remove_target.push_back({disk_num, 0});
            remove_target.push_back({disk_num, m - 1});
        }
    }
    for (int direct = 0; direct < m; ++direct)
        for (int disk_num = 1; disk_num < n; ++disk_num)
            if (disks[disk_num][direct] && disks[disk_num][direct] == disks[disk_num + 1][direct])
            {
                remove_target.push_back({disk_num, direct});
                remove_target.push_back({disk_num + 1, direct});
            }
    return remove_target;
}

void adjust_disk_data()
{
    if (auto remove_target = move(get_remove_target()); remove_target.empty())
    {
        long double total_sum = 0, total_ea = 0;
        for (int i = 1; i <= n; ++i)
        {
            total_sum += disks[i].sum();
            total_ea += disks[i].valid_data_ea();
        }
        long double avg = total_sum / total_ea;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (disks[i][j] == 0)
                    continue;
                if (disks[i][j] < avg)
                    ++disks[i][j];
                else if (disks[i][j] > avg)
                    --disks[i][j];
            }
    }
    else
    {
        for (const auto& [disk_num, idx] : remove_target)
            disks[disk_num][idx] = 0;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> t;
    disks.reserve(n + 1);
    disks.push_back(Disk{});
    for (int i = 0; i < n; ++i)
    {
        vector<int> tmp(m);
        for (int i = 0; i < m; ++i)
            cin >> tmp[i];
        disks.emplace_back(tmp);
    }
    while (t--)
    {
        int x, d, k;
        cin >> x >> d >> k;
        for (int i = x; i < disks.size(); i += x)
            for (int j = 0; j < k; ++j)
            {
                if (d)
                    disks[i].rotate_counter_clock();
                else
                    disks[i].rotate_clock();
            }
        adjust_disk_data();
    }
    int total_sum = 0;
    for (int i = 1; i <= n; ++i)
        total_sum += disks[i].sum();
    cout << total_sum;
    return 0;
}