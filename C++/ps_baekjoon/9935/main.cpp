//baekjoon ps 9935

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string str, bomb;
    cin >> str >> bomb;
    char trigger = bomb.back();
    deque<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        s.push_back(c);
        if (c == trigger)
        {
            string cmp = "";
            for (int j = s.size() - 1; j >= s.size() - bomb.size() && j >= 0; j--)
                cmp = s[j] + cmp;
            if (cmp == bomb)
                for (int i = 0; i < bomb.size(); i++)
                    s.pop_back();
        }
    }
    if (s.empty())
        cout << "FRULA";
    else
        for (const auto &e : s)
            cout << e;
    return 0;
}