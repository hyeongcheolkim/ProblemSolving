#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<string, int, int, int>> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        string name;
        int dd, mm, yyyy;
        cin >> name >> dd >> mm >> yyyy;
        arr.emplace_back(name, dd, mm, yyyy);
    }
    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
        const auto& [a_name, a_dd, a_mm, a_yyyy] = a;
        const auto& [b_name, b_dd, b_mm, b_yyyy] = b;
        if (a_yyyy == b_yyyy)
        {
            if (a_mm == b_mm)
                return a_dd < b_dd;
            else
                return a_mm < b_mm;
        }
        else
            return a_yyyy < b_yyyy;
    });
    cout << get<0>(arr.back()) << '\n' << get<0>(arr.front());
    return 0;
}