#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    unordered_map<string, int> book;
    while (n--)
    {
        string name;
        cin >> name;
        ++book[name];
    }
    vector<pair<string, int>> vec_book{book.begin(), book.end()};
    sort(vec_book.begin(), vec_book.end(), [](auto& a, auto& b) {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second > b.second;
    });
    cout << vec_book.front().first;
    return 0;
}