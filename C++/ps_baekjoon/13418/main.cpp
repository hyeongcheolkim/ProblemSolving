#include <bits/stdc++.h>
using namespace std;
using vertex = tuple<int, int, int>;

int n, m;
priority_queue<vertex, vector<vertex>, less<vertex>> lpq;
priority_queue<vertex, vector<vertex>, greater<vertex>> gpq;

class unionFind
{
private:
    vector<int> uf;
    int cnt, k;
public:
    unionFind(const int& num) : cnt{0}, k{0}
    {
        uf.resize(num + 1);
        iota(uf.begin(), uf.end(), 0);
    }
    int find(int num)
    {
        if (uf[num] == num)
            return num;
        return uf[num] = find(uf[num]);
    }
    void uni(int slope, int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            uf[a] = b;
            ++cnt;
            if (!slope)
                ++k;
        }
    }
    int get_cnt() { return this->cnt; }
    int get_k() { return this->k; }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i <= m; ++i)
    {
        int from, to, slope;
        cin >> from >> to >> slope;
        lpq.emplace(slope, from, to);
        gpq.emplace(slope, from, to);
    }
    unionFind mini(n), maxi(n);
    while (!lpq.empty() && mini.get_cnt() < n)
    {
        auto [slope, from, to] = lpq.top();
        lpq.pop();
        mini.uni(slope, from, to);
    }
    while (!gpq.empty() && maxi.get_cnt() < n)
    {
        auto [slope, from, to] = gpq.top();
        gpq.pop();
        maxi.uni(slope, from, to);
    }
    cout << pow(maxi.get_k(), 2) - pow(mini.get_k(), 2);
    return 0;
}