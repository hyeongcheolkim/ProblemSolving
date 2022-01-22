#include <bits/stdc++.h>
using namespace std;

unordered_map<string, long long> table
{
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green", 5},
    {"blue", 6},
    {"violet", 7},
    {"grey", 8},
    {"white", 9},
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string first, second, third;
    cin >> first >> second >> third;
    cout << (table[first] * 10 + table[second]) * static_cast<long long>(pow(10, table[third]));
    return 0;
}