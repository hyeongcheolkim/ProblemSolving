#include <bits/stdc++.h>
using namespace std;

int n, answer = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    set<string> s;
    while(n--)
    {
        string str;
        cin >> str;
        if(str == "ENTER")
        {
            answer += s.size();
            s.clear();
            continue;
        }
        s.insert(str);
    }
    answer += s.size();
    cout << answer;
    return 0;
}