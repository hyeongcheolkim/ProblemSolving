#include <bits/stdc++.h>
using namespace std;

enum class word { TAG, WORD };

stack<char> s;
queue<char> q;
char buff;
word mode = word::WORD;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while ((buff = cin.get()) != '\n')
    {
        if (buff == '<')
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            mode = word::TAG;
        }
        if (mode == word::TAG)
        {
            q.push(buff);
            if (buff == '>')
                while (!q.empty())
                {
                    cout << q.front();
                    q.pop();
                    mode = word::WORD;
                }
        }
        else if (mode == word::WORD)
        {
            if (buff == ' ')
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            }
            else
                s.push(buff);
        }
    }
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}