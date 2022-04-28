#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> guitars;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    guitars.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> guitars[i];
    sort(guitars.begin(), guitars.end(), [](const string& a, const string& b) {
        if (a.length() == b.length())
        {
            int sum_a = 0, sum_b = 0;
            for (const auto& e : a)
                if ('0' <= e && e <= '9')
                    sum_a = sum_a + e - '0';
            for (const auto& e : b)
                if ('0' <= e && e <= '9')
                    sum_b = sum_b + e - '0';
            if (sum_a == sum_b)
                return a < b;
            else
                return sum_a < sum_b;
        }
        else
            return a.length() < b.length();
    });
    for (const auto& guitar : guitars)
        cout << guitar << '\n';
    return 0;
}