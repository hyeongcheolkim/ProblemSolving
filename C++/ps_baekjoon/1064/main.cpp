#include <bits/stdc++.h>
using namespace std;
using pos = pair<long double, long double>;

pos a, b, c;

long double distance(pos n, pos m)
{
    return sqrt(pow((n.first - m.first), 2) + pow((n.second - m.second), 2));
}

bool is_same_inclination(pos a, pos b, pos c)
{
    return (a.second - b.second) * (b.first - c.first) == (b.second - c.second) * (a.first - b.first);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    vector<long double>arr = {distance(a, b), distance(b, c), distance(a, c)};
    sort(arr.begin(), arr.end());
    if (is_same_inclination(a, b, c))
        cout << "-1.0";
    else
    {
        cout.precision(16);
        cout << fixed << (arr.back() - arr.front()) * 2;
    }
    return 0;
}