#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> alphabet('z' - 'a' + 1);
        int res = 0;
        char buff;
        while ((buff = cin.get()) != '\n')
            if (++alphabet[buff - 'a'] == 2)
            {
                alphabet[buff - 'a'] -= 2;
                for (auto& e : alphabet)
                {
                    res += e;
                    e = 0;
                }
            }
        for (auto& e : alphabet)
            res += e;
        cout << res << '\n';
    }
    return 0;
}