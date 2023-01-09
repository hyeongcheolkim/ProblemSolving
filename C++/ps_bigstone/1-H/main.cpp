#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, string> num_dict;
unordered_map<string, int> name_dict;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        string name;
        cin >> name;
        num_dict[i] = name;
        name_dict[name] = i;
    }
    while (m--)
    {
        string q;
        cin >> q;
        if (all_of(q.begin(), q.end(), [](const auto& e) {return isdigit(e); }))
            cout << num_dict[stoi(q)] << '\n';
        else
            cout << name_dict[q] << '\n';
    }
    return 0;
}