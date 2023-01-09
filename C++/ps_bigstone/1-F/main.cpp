#include <bits/stdc++.h>
using namespace std;

string str;

char ROT13(unsigned char c)
{
    if (islower(c))
    {
        c += 13;
        if (c > 'z')
            c = 'a' + c % 'z' - 1;
    }
    if (isupper(c))
    {
        c += 13;
        if (c > 'Z')
            c = 'A' + c % 'Z' - 1;
    }
    return c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    getline(cin, str);
    for_each(str.begin(), str.end(), [](auto& e) {e = ROT13(e); });
    cout << str;
    return 0;
}