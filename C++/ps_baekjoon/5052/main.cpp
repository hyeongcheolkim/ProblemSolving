//baekjoon ps 5052

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool flag = true;
        cin >> n;
        vector<string> number(n);
        for (int i = 0; i < n; ++i)
            cin >> number[i];
        sort(number.begin(), number.end());
        for (int idx = 0; idx < n - 1; ++idx)
            if (number[idx] == number[idx + 1].substr(0, number[idx].size()))
            {
                flag = false;
                break;
            }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}