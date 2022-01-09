#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n, n != 0)
    {
        cin.ignore();
        vector<vector<string>> data;
        data.reserve(n);
        bool flag = true;
        cout << "Group " << cnt++ << '\n';
        for (int iter = 0; iter < n; ++iter)
        {
            string input;
            getline(cin, input);
            auto parse = input | views::split(' ') | views::transform([](auto v) {auto c = v | views::common; return string(c.begin(), c.end()); });
            data.emplace_back(parse.begin(), parse.end());
        }
        for (int i = 0; i < n; ++i)
        {
            auto& to_name = data[i].front();
            for (int j = 1; j < n; ++j)
                if (data[i][j] == "N")
                {
                    flag = false;
                    int idx = i - j;
                    auto& from_name = data[idx >= 0 ? idx : n + idx].front();
                    cout << from_name << " was nasty about " << to_name << '\n';
                }
        }
        if (flag)
            cout << "Nobody was nasty\n";
        cout << '\n';
    }
    return 0;
}