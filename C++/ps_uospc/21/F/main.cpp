#include <bits/stdc++.h>
using namespace std;

int t, m, n;
map<char, int> to;
unordered_map<char, deque<char>> preferM;
unordered_map<char, deque<char>> preferN;
unordered_map<char, deque<char>> pass;
unordered_map<char, char> candidate;
unordered_map<char, map<char, int>> idx;
unordered_map<char, bool> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        char club, temp;
        int num;
        cin >> club >> num;
        to[club] = num;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            preferM[club].push_back(temp);
            idx[club][temp] = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        char name, temp;
        int ea;
        cin >> name >> ea;
        for (int i = 0; i < ea; ++i)
        {
            cin >> temp;
            preferN[name].push_back(temp);
        }
    }
    while (t--)
    {
        for (auto& e : preferN)
        {
            auto& name = e.first;
            auto& prefer = e.second;
            if (!prefer.empty())
            {
                candidate[name] = prefer.front();
                prefer.pop_front();
            }
        }
        for (auto& e : preferM)
        {
            auto& name = e.first;
            auto& prefer = e.second;
            for (auto& e : prefer)
                if (candidate[e] == name)
                {
                    if (pass[name].size() == to[name])
                    {
                        auto out = pass[name].back();
                        if (idx[name][out] > idx[name][e])
                        {
                            pass[name].pop_back();
                            pass[name].push_back(e);
                        }
                    }
                    else
                        pass[name].push_back(e);
                }
        }
    }
    for (char i = 'A'; i < 'A' + m; ++i)
    {
        auto& name = i;
        cout << name << ' ';
        for (auto& e : pass[i])
            cout << e << ' ';
        cout << '\n';
    }
    return 0;
}