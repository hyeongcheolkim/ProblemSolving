#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    unordered_map<string, bool> log;
    while (n--)
    {
        string name, state;
        cin >> name >> state;
        if (state == "enter")
            log[name] = true;
        else
            log[name] = false;
    }
    vector<string> res;
    for (const auto& [name, state] : log)
        if (state)
            res.push_back(name);
    sort(res.begin(), res.end(), greater<string>());
    for (const auto& name : res)
        cout << name << '\n';
    return 0;
}