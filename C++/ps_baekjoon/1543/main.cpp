#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int res = 0;
    string str, word;
    getline(cin, str);
    getline(cin, word);
    if (str.size() < word.size())
    {
        cout << res;
        exit(0);
    }
    for (int i = 0; i <= str.size() - word.size() + 1; ++i)
    {
        string sub_str = str.substr(i, word.size());
        if (sub_str == word)
        {
            ++res;
            i += word.size() - 1;
        }
    }
    cout << res;
}