#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, tmp;
        unordered_map<int, bool> note1;
        cin >> n;
        while (n--)
        {
            cin >> tmp;
            note1[tmp] = true;
        }
        cin >> m;
        while (m--)
        {
            cin >> tmp;
            cout << note1[tmp] << '\n';
        }
    }
    return 0;
}