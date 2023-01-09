#include <bits/stdc++.h>
using namespace std;

int n;
string regex_str;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> regex_str;
    regex_str.replace(regex_str.find_first_of("*"), 1, "\\w*");
    regex re{regex_str};
    while (n--)
    {
        string name;
        cin >> name;
        if (regex_match(name, re))
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
    return 0;
}