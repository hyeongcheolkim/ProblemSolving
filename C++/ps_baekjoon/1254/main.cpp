#include <bits/stdc++.h>
using namespace std;

string str;
int max_len = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    reverse(str.begin(), str.end());
    for (int i = 1; i <= str.size(); ++i)
    {
        string sub = str.substr(0, i);
        auto rsub = sub;
        reverse(rsub.begin(), rsub.end());
        if (sub == rsub)
            max_len = max(max_len, i);
    }
    cout << max_len + (str.size() - max_len) * 2;
    return 0;
}