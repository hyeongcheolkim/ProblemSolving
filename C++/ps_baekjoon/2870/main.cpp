#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        string str, buff;
        auto to_num = [&]
        {
            while (buff.size() >= 2 && buff.front() == '0')
                buff.erase(buff.begin());
            res.push_back(buff);
            buff.clear();
        };
        cin >> str;
        for (const auto& c : str)
        {
            if (isdigit(c))
                buff.push_back(c);
            else if (!buff.empty())
                to_num();
        }
        if (!buff.empty())
            to_num();
    }
    sort(res.begin(), res.end(), [](auto& str1, auto& str2) {
        if (str1.size() == str2.size())
            return str1 < str2;
        else
            return str1.size() < str2.size();
    });
    for (const auto& e : res)
        cout << e << '\n';
    return 0;
}