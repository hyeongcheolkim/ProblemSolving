#include <bits/stdc++. h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    int s_size = s.size();
    int reverse_state = 0;
    while (s_size != t.size())
    {
        if (t.back() == 'A')
            t.pop_back();
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    cout << (s == t ? 1 : 0);
    return 0;
}