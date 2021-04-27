//baekjoon ps 1874

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    bool flag = true;
    cin >> n;
    stack<unsigned int> s;
    vector<char> res;
    for (int i = 1; i <= n; i++)
    {
        static unsigned input;
        static int index=1;
        cin >> input;
        if (input >= index)
        {
            for (; index <= input; index++)
            {
                s.push(index);
                res.push_back('+');
            }
            s.pop();
            res.push_back('-');
        }
        else
        {
            if (s.top() == input)
            {
                s.pop();
                res.push_back('-');
            }
            else
                flag = false;
        }
    }
    if (flag)
        for (const auto &e : res)
            cout << e << '\n';
    else
        cout << "NO";

    return 0;
}