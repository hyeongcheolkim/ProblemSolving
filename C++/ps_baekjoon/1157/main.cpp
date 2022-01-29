#include <bits/stdc++.h>
using namespace std;

string word;
map<char, int> cnt;
char res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> word;
    for_each(word.begin(), word.end(), [](const auto& e) { ++cnt[toupper(e)]; });
    for (int maxi = -1; const auto & [alphabet, ea] : cnt)
        if (ea > maxi)
        {
            maxi = ea;
            res = alphabet;
        }
        else if (ea == maxi)
            res = '?';
    cout << res;
    return 0;
}