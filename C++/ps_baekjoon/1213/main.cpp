#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    map<char, int> alphabet;
    char odd = 0;
    string str, str1, str2;
    cin >> str;
    for (const auto& e : str)
        ++alphabet[e];
    for (const auto& [chr, cnt] : alphabet)
    {
        if (cnt % 2 == 0)
            for (int i = 0; i < cnt / 2; ++i)
            {
                str1 = str1 + chr;
                str2 = chr + str2;
            }
        else
        {
            if (odd != 0)
            {
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
            for (int i = 0; i < cnt / 2; ++i)
            {
                str1 = str1 + chr;
                str2 = chr + str2;
            }
            odd = chr;
        }
    }
    if (odd == 0)
        cout << str1 << str2;
    else
        cout << str1 << odd << str2;
    return 0;
}