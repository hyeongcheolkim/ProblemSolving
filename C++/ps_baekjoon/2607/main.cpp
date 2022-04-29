#include <bits/stdc++.h>
using namespace std;

int n, res, len_target;
string str;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    map<char, int> target;
    cin >> str;
    len_target = str.length();
    for (const auto& e : str)
        ++target[e];
    while (--n)
    {
        cin >> str;
        int cnt = 0;
        map<char, int> compared;
        auto tmp = target;
        for (const auto& e : str)
            ++compared[e];
        for (const auto& [chr, ea] : compared)
            tmp[chr] -= ea;
        for (const auto& [chr, ea] : tmp)
            cnt += abs(ea);
        if (len_target == str.length() && cnt <= 2)
            ++res;
        else if (cnt <= 1)
            ++res;
    }
    cout << res;
    return 0;
}